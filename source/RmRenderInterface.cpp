#include "RmRenderInterface.h"
#include <UniginePtr.h>
using namespace Unigine;

static RmRenderJob* renderJob;

RmRenderInterface::RmRenderInterface()
{
}

void RmRenderInterface::Construct()
{
}

void RmRenderInterface::Init()
{
	

	CreateRenderMesh();
	CreateRenderMaterial();
}

void RmRenderInterface::RenderGeometry(Rml::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::Core::TextureHandle texture, const Rml::Core::Vector2f& translation)
{
	if (!rml_mesh)
		return;

	rml_mesh->clearVertex();
	rml_mesh->clearIndices();
	rml_mesh->allocateVertex(num_vertices);
	rml_mesh->allocateIndices(num_indices);
	for (int i = 0; i < num_vertices; i++) {
		rml_mesh->addVertexArray(vertices, num_vertices);
		rml_mesh->addIndicesArray(indices, num_indices);
	}
	rml_mesh->flushVertex();
	rml_mesh->flushIndices();

	auto render_target = Render::getTemporaryRenderTarget();
	render_target->bindColorTexture(0, Renderer::getTextureColor());

	RenderState::saveState();
	RenderState::clearStates();
	RenderState::setBlendFunc(RenderState::BLEND_SRC_ALPHA, RenderState::BLEND_ONE_MINUS_SRC_ALPHA, RenderState::BLEND_OP_ADD);
	RenderState::setPolygonCull(RenderState::CULL_NONE);
	RenderState::setDepthFunc(RenderState::DEPTH_NONE);
	RenderState::setViewport(static_cast<int>(translation.x), static_cast<int>(translation.y),
		static_cast<int>(1920), static_cast<int>(1080));

	float left = translation.x;
	float right = translation.x +translation.x;
	float top = translation.y;
	float bottom =translation.y + translation.y;

	Math::Mat4 proj;
	proj.m00 = 2.0f / (right - left);
	proj.m03 = (right + left) / (left - right);
	proj.m11 = 2.0f / (top - bottom);
	proj.m13 = (top + bottom) / (bottom - top);
	proj.m22 = 0.5f;
	proj.m23 = 0.5f;
	proj.m33 = 1.0f;

	Renderer::setProjection(proj);

	auto shader = rml_material->fetchShader("rml");
	auto pass = rml_material->getRenderPass("rml");

	Renderer::setShaderParameters(pass, shader, rml_material, false);

	if (texture) {

		rml_mesh->bind();
		render_target->enable();
		{
			if (!texture) {
				TexturePtr rmTexture = Texture::create();
				rmTexture->create2D(20, 20, Texture::FORMAT_RGBA8, Texture::DEFAULT_FLAGS);
				rml_material->setTexture("rml_texture", rmTexture);
			}
			else {
				auto tex = TexturePtr(static_cast<Texture*>((void*)texture));
				rml_material->setTexture("rml_texture", tex);
			}
		}
		render_target->disable();
		rml_mesh->unbind();

	}

	RenderState::restoreState();

	render_target->unbindColorTexture(0);
	Render::releaseTemporaryRenderTarget(render_target);

}

Rml::Core::CompiledGeometryHandle RmRenderInterface::CompileGeometry(Rml::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::Core::TextureHandle texture)
{
	return Rml::Core::CompiledGeometryHandle();
}

void RmRenderInterface::RenderCompiledGeometry(Rml::Core::CompiledGeometryHandle geometry, const Rml::Core::Vector2f& translation)
{
}

void RmRenderInterface::ReleaseCompiledGeometry(Rml::Core::CompiledGeometryHandle geometry)
{
}

void RmRenderInterface::EnableScissorRegion(bool enable)
{
}

void RmRenderInterface::SetScissorRegion(int x, int y, int width, int height)
{
}

bool RmRenderInterface::LoadTexture(Rml::Core::TextureHandle& texture_handle, Rml::Core::Vector2i& texture_dimensions, const Rml::Core::String& source)
{
	TexturePtr rmTexture = Texture::create();
	rmTexture->load(source.c_str());

	texture_handle = (uintptr_t)rmTexture.get();

	return true;
}

bool RmRenderInterface::GenerateTexture(Rml::Core::TextureHandle& texture_handle, const Rml::Core::byte* source, const Rml::Core::Vector2i& source_dimensions)
{
	unsigned char* pixels = (unsigned char*)source;
	int width = source_dimensions.x;
	int height = source_dimensions.y;

	TexturePtr rmTexture = Texture::create();
	rmTexture->create2D(width, height, Texture::FORMAT_RGBA8, Texture::DEFAULT_FLAGS);

	auto blob = Blob::create();
	blob->setData(pixels, width * height * 4);
	rmTexture->setBlob(blob);
	blob->setData(nullptr, 0);

	texture_handle = (uintptr_t)rmTexture.get();

	return true;
}

void RmRenderInterface::ReleaseTexture(Rml::Core::TextureHandle texture_handle)
{
	auto texture = TexturePtr(static_cast<Texture*>((void*)texture_handle));
	texture.deleteLater();
}


void RmRenderInterface::CreateRenderMesh()
{
	rml_mesh = MeshDynamic::create(MeshDynamic::DYNAMIC_ALL);

	MeshDynamic::Attribute attributes[3]{};
	attributes[0].offset = 0;
	attributes[0].size = 2;
	attributes[0].type = MeshDynamic::TYPE_FLOAT;
	attributes[1].offset = 8;
	attributes[1].size = 2;
	attributes[1].type = MeshDynamic::TYPE_FLOAT;
	attributes[2].offset = 16;
	attributes[2].size = 4;
	attributes[2].type = MeshDynamic::TYPE_UCHAR;
	rml_mesh->setVertexFormat(attributes, 3);

	/*assert(imgui_mesh->getVertexSize() == sizeof(ImDrawVert) && "Vertex size of MeshDynamic is not equal to size of ImDrawVert");*/

}

void RmRenderInterface::CreateRenderMaterial()
{
	rml_material = Materials::findMaterial("rml")->inherit();

}
