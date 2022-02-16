#include "okrapch.h"
#include "LayerStack.h"

okra::LayerStack::LayerStack() {}

okra::LayerStack::~LayerStack()
{
	for (auto layer : m_Layers)
		delete layer;
}

void okra::LayerStack::pushLayer(Layer* layer)
{
	m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
	m_LayerInsertIndex++;
}

void okra::LayerStack::pushOverlay(Layer* overlay)
{
	m_Layers.emplace_back(overlay);
}

void okra::LayerStack::popLayer(Layer* layer)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
	if (it != m_Layers.end())
	{
		m_Layers.erase(it);
		m_LayerInsertIndex--;
	}
}

void okra::LayerStack::popOverlay(Layer* overlay)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
	if (it != m_Layers.end())
		m_Layers.erase(it);
}
