// OGLRenderEffect.hpp
// KlayGE OpenGL渲染效果类 头文件
// Ver 2.8.0
// 版权所有(C) 龚敏敏, 2004-2005
// Homepage: http://klayge.sourceforge.net
//
// 2.8.0
// 使用Cg实现 (2005.7.30)
//
// 2.5.0
// 去掉了Clone (2005.4.16)
//
// 2.0.4
// 初次建立 (2004.4.4)
//
// 修改记录
//////////////////////////////////////////////////////////////////////////////////

#ifndef _OGLRENDEREFFECT_HPP
#define _OGLRENDEREFFECT_HPP

#include <KlayGE/PreDeclare.hpp>
#include <KlayGE/RenderEffect.hpp>

#include <Cg/cg.h>
#include <Cg/cgGL.h>

#ifdef KLAYGE_DEBUG
	#pragma comment(lib, "KlayGE_RenderEngine_OpenGL_d.lib")
#else
	#pragma comment(lib, "KlayGE_RenderEngine_OpenGL.lib")
#endif

namespace KlayGE
{
	// 渲染效果
	//////////////////////////////////////////////////////////////////////////////////
	class OGLRenderEffect : public RenderEffect
	{
	public:
		explicit OGLRenderEffect(std::string const & srcData);
		~OGLRenderEffect();

		bool Validate(std::string const & technique);
		void SetTechnique(std::string const & technique);

		void BeginPass(uint32_t passNum);
		void EndPass();

	private:
		std::string DoNameBySemantic(std::string const & semantic);
		RenderEffectParameterPtr DoParameterByName(std::string const & name);

		uint32_t DoBegin(uint32_t flags);
		void DoEnd();

	private:
		CGeffect effect_;
		CGtechnique technique_;
	};

	class OGLRenderEffectParameter : public RenderEffectParameter
	{
	public:
		explicit OGLRenderEffectParameter(RenderEffect& effect, std::string const & name, CGparameter param);
		~OGLRenderEffectParameter();

	private:
		bool DoTestType(RenderEffectParameterType type);

		void DoFloat(float value);
		void DoVector4(Vector4 const & value);
		void DoMatrix4(Matrix4 const & value);
		void DoInt(int value);
		void DoTexture(TexturePtr const & value);

		void DoSetFloatArray(float const * value, size_t count);
		void DoSetVector4Array(Vector4 const * value, size_t count);
		void DoSetMatrix4Array(Matrix4 const * value, size_t count);
		void DoSetIntArray(int const * value, size_t count);

	private:
		CGparameter param_;

	private:
		OGLRenderEffectParameter(OGLRenderEffectParameter const & rhs);
		OGLRenderEffectParameter& operator=(OGLRenderEffectParameter const & rhs);
	};
}

#endif		// _OGLRENDEREFFECT_HPP
