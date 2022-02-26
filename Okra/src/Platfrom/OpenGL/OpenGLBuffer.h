#pragma once

#include "Okra/Renderer/Buffer.h"

namespace okra
{

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void bind() const override;
		virtual void unbind() const override;
	
	private:
		uint32_t m_RendererID;
	};
	
	///////////////////////////////////////////////////////////////////////
	// Index buffer ///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////


	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* vertices, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual uint32_t getCount() const { return m_Count; }
	private:
		uint32_t m_Count;
		uint32_t m_RendererID;
	};
}