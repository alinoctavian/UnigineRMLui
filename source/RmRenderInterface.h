#pragma once

#include <RmlUi/Core.h>

#include <UnigineApp.h>
#include <UnigineConsole.h>
#include <UnigineEngine.h>
#include <UnigineGame.h>
#include <UnigineLights.h>
#include <UnigineLogic.h>
#include <UnigineMaterials.h>
#include <UnigineObjects.h>
#include <UniginePlugin.h>
#include <UnigineRender.h>
#include <UnigineWorld.h>
#include <UnigineFfp.h>
#include <UnigineImage.h>
#include <UnigineTextures.h>
#include <UnigineMeshDynamic.h>
#include <UnigineMaterials.h>

struct  RmRenderJob {
	RmRenderJob(Rml::Core::Vertex* vertices,
		int num_vertices,
		int* indices,
		int num_indices,
		Rml::Core::TextureHandle texture,
		const Rml::Core::Vector2f& translation) : vertices(vertices), 
		num_vertices(num_vertices),
		indices(indices),
		num_indices(num_indices),
		texture(texture),
		translation(translation) {};

	Rml::Core::Vertex* vertices;
	int num_vertices;
	int* indices;
	int num_indices;
	Rml::Core::TextureHandle texture;
	const Rml::Core::Vector2f& translation;
};


class RmRenderInterface : public Rml::Core::RenderInterface
{
	Unigine::MeshDynamicPtr rml_mesh;
	Unigine::MaterialPtr rml_material;


	void* draw_callback_handle;
public:
	RmRenderInterface();

	void Construct();

	void Init();

	void RenderGeometry(Rml::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::Core::TextureHandle texture, const Rml::Core::Vector2f& translation) override;

	/// Called by RmlUi when it wants to compile geometry it believes will be static for the forseeable future.
	Rml::Core::CompiledGeometryHandle CompileGeometry(Rml::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::Core::TextureHandle texture) override;

	/// Called by RmlUi when it wants to render application-compiled geometry.
	void RenderCompiledGeometry(Rml::Core::CompiledGeometryHandle geometry, const Rml::Core::Vector2f& translation) override;
	/// Called by RmlUi when it wants to release application-compiled geometry.
	void ReleaseCompiledGeometry(Rml::Core::CompiledGeometryHandle geometry) override;

	/// Called by RmlUi when it wants to enable or disable scissoring to clip content.
	void EnableScissorRegion(bool enable) override;
	/// Called by RmlUi when it wants to change the scissor region.
	void SetScissorRegion(int x, int y, int width, int height) override;

	/// Called by RmlUi when a texture is required by the library.
	bool LoadTexture(Rml::Core::TextureHandle& texture_handle, Rml::Core::Vector2i& texture_dimensions, const Rml::Core::String& source) override;
	/// Called by RmlUi when a texture is required to be built from an internally-generated sequence of pixels.
	bool GenerateTexture(Rml::Core::TextureHandle& texture_handle, const Rml::Core::byte* source, const Rml::Core::Vector2i& source_dimensions) override;
	/// Called by RmlUi when a loaded texture is no longer required.
	void ReleaseTexture(Rml::Core::TextureHandle texture_handle) override;


private:

	void CreateRenderMesh();
	void CreateRenderMaterial();
};

