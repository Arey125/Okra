#include "okrapch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platfrom/OpenGL/OpenGLBuffer.h"

namespace okra
{

	VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size)
	{
		switch (Renderer::getAPI())
		{
		case RendererAPI::None:
			OKRA_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		default:
			break;	
		}

		OKRA_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::create(uint32_t* vertices, uint32_t size)
	{
		switch (Renderer::getAPI())
		{
		case RendererAPI::None:
			OKRA_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(vertices, size);
		default:
			break;
		}

		OKRA_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}