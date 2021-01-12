#include "RmRenderInterface.h"


RmRenderInterface::RmRenderInterface()
{
	

}

void RmRenderInterface::Initialize()
{
	Width = App::getWidth();
	Height = App::getHeight();
}

void RmRenderInterface::RenderGeometry(Rml::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::Core::TextureHandle texture, const Rml::Core::Vector2f& translation)
{

	RenderTargetPtr render_target = Renderer::getRenderTarget();
	TexturePtr tex = Renderer::getTextureColor();

	// bind color texture
	render_target->bindColorTexture(0, tex);
	// bind depth texture
	// in this callback depth texture already binded to our scene
	// render_target->bindDepthTexture(..

	render_target->enable();
	{
		RenderState::setDepthFunc(RenderState::DEPTH_NONE);
		RenderState::setBlendFunc(RenderState::BLEND_SRC_ALPHA, RenderState::BLEND_ONE_MINUS_SRC_ALPHA);
		RenderState::flushStates();

		Ffp::enable(Ffp::MODE_SOLID);
		Ffp::setOrtho(Width, Height);
		Ffp::beginTriangles();
		TexturePtr* _texture = nullptr;
		if (texture) {
			_texture = (TexturePtr*)texture;

		}
		for (int i = 0; i < num_vertices; i++) {
			Ffp::addVertex(vertices[i].position.x, vertices[i].position.y);
			Ffp::setColor(vertices[i].colour.red, vertices[i].colour.green, vertices[i].colour.blue, vertices[i].colour.alpha);

			if (_texture)
				Ffp::setTexCoord(vertices[i].tex_coord.x, vertices[i].tex_coord.y, 1);
		}
		for (int i = 0; i < num_indices; i++) {
			Ffp::addIndex(indices[i]);
		}
		Ffp::endTriangles();
		Ffp::disable();
	}


	render_target->disable();
	render_target->unbindColorTextures();

}

Rml::Core::CompiledGeometryHandle RmRenderInterface::CompileGeometry(Rml::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::Core::TextureHandle texture)
{
	return (Rml::Core::CompiledGeometryHandle)nullptr;
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

	TexturePtr texture = Texture::create();
	texture->load(source.c_str());


	texture_dimensions.x = texture->getWidth();
	texture_dimensions.y = texture->getHeight();
	texture_handle = (Rml::Core::TextureHandle)texture.get();


    return true;
}

bool RmRenderInterface::GenerateTexture(Rml::Core::TextureHandle& texture_handle, const Rml::Core::byte* source, const Rml::Core::Vector2i& source_dimensions)
{


    return true;
}

void RmRenderInterface::ReleaseTexture(Rml::Core::TextureHandle texture_handle)
{




}
