#ifndef DCAN_AST_LISTENER_USER_MODELEXTRACTOR_H
#define DCAN_AST_LISTENER_USER_MODELEXTRACTOR_H

#include "dcan/Ast/Listener/EnterExitListener.h"
#include "dcan/Ast/Reference/Access.h"
#include "dcan/Ir/Model/Element.h"
#include "dcan/Ir/Model/Model.h"
#include "dcan/Ir/Model/Node.h"
#include "dcan/Ir/Model/Source.h"
#include <variant>

namespace dcan::ast::listener::model
{
	class ModelExtractor : public EnterExitListener
	{
	private:
		std::unique_ptr<ir::model::Model> model;

	public:
		ModelExtractor()
		{
			model = std::make_unique<ir::model::Model>();
		}
		virtual ~ModelExtractor() override = default;

	public:
		void ListenEntry(const dcan::ast::node::node_declaration* node) override
		{
			auto Access = reference::Access(node);
			auto nodeName = Access.node_name().GetContent()[0]->GetText();
			model->CreateNode(nodeName, false);
		}

		void ListenEntry(const dcan::ast::node::source_declaration* node) override
		{
			auto Access = reference::Access(node);
			auto sourceName = Access.source_name().GetContent()[0]->GetText();
			model->CreateElement(sourceName, ir::model::ElementType::combined);
		}

		void ListenEntry(const dcan::ast::node::ground_declaration* node) override
		{
			auto Access = reference::Access(node);
			auto nodeObject = model->GetNode(Access.ground_name().GetContent()[0]->GetText());
			if (nodeObject == nullptr)
			{
				return;
			}

			nodeObject->SetGround();
		}

		void ListenEntry(const dcan::ast::node::connection* node) override
		{
			auto Access = reference::Access(node);
			std::optional<std::variant<ir::model::Node*, ir::model::Source*>> lastComponentCache;
			Access.component_name().for_all([&](const node::component_name* const component) {
				auto componentName = component->GetText();
				if (lastComponentCache.has_value())
				{
					auto lastComponent = lastComponentCache.value();
					auto nodeObject = model->GetNode(componentName);
					if (nodeObject != nullptr)
					{
						if (std::holds_alternative<ir::model::Node*>(lastComponent))
						{
							auto lastComponent_ = std::get<ir::model::Node*>(lastComponent);
							lastComponent_->Merge(nodeObject);
						}
						else if (std::holds_alternative<ir::model::Source*>(lastComponent))
						{
							auto lastComponent_ = std::get<ir::model::Source*>(lastComponent);
							lastComponent_->LinkWithNode(nodeObject);
						}
						lastComponentCache = nodeObject;
						return;
					}

					auto source = model->GetSource(componentName);
					if (source != nullptr)
					{
						if (std::holds_alternative<ir::model::Node*>(lastComponent))
						{
							auto lastComponent_ = std::get<ir::model::Node*>(lastComponent);
							lastComponent_->LinkWithSource(source);
						}
						else if (std::holds_alternative<ir::model::Source*>(lastComponent))
						{
							auto lastComponent_ = std::get<ir::model::Source*>(lastComponent);
							lastComponent_->LinkWithSource(source);
						}
						lastComponentCache = source;
						return;
					}
				}
				else
				{
					auto nodeObject = model->GetNode(componentName);
					if (nodeObject != nullptr)
					{
						lastComponentCache = nodeObject;
					}

					auto source = model->GetSource(componentName);
					if (source != nullptr)
					{
						lastComponentCache = source;
					}
				}
			});
		}

		void ListenEntry(const dcan::ast::node::assignment* node) override
		{
			auto Access = reference::Access(node);
			auto source = model->GetSource(Access.lhs_component_name().GetContent()[0]->GetText());

			if (!Access.unit_value().voltage_value().GetContent().empty())
			{
				source->AssignVoltage(std::stoi(
					Access.unit_value().voltage_value().value().GetContent()[0]->GetText()));
			}
			else if (!Access.unit_value().current_value().GetContent().empty())
			{
				source->AssignCurrent(std::stoi(
					Access.unit_value().current_value().value().GetContent()[0]->GetText()));
			}
			else if (!Access.unit_value().resistance_value().GetContent().empty())
			{
				source->AssignResistance(std::stoi(
					Access.unit_value().resistance_value().value().GetContent()[0]->GetText()));
			}
		}

		std::unique_ptr<ir::model::Model> GetModel()
		{
			auto tmp = std::move(model);
			model = std::make_unique<ir::model::Model>();
			return std::move(tmp);
		}
	};
}

#endif // DCAN_AST_LISTENER_USER_MODELEXTRACTOR_H
