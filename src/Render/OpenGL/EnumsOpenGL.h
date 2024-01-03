/*
 * SoftGLRender
 * @author 	: keith@robot9.me
 *
 */

#pragma once

#include "Render/Texture.h"
#include "Render/PipelineStates.h"

namespace SoftGL {
namespace OpenGL {

#define CASE_CVT_GL(PRE, TOKEN) case PRE##TOKEN: return GL_##TOKEN

static inline GLint cvtWrap(WrapMode mode) {
  switch (mode) {
    case Wrap_REPEAT:                     return GL_REPEAT;
    case Wrap_MIRRORED_REPEAT:            return GL_MIRRORED_REPEAT;
    case Wrap_CLAMP_TO_EDGE:              return GL_CLAMP_TO_EDGE;
    case Wrap_CLAMP_TO_BORDER:            return GL_CLAMP_TO_BORDER;

    // CASE_CVT_GL(Wrap_, REPEAT);
    // CASE_CVT_GL(Wrap_, MIRRORED_REPEAT);
    // CASE_CVT_GL(Wrap_, CLAMP_TO_EDGE);
    // CASE_CVT_GL(Wrap_, CLAMP_TO_BORDER);
    default:
      break;
  }
  return GL_REPEAT;
}

static inline GLint cvtFilter(FilterMode mode) {
  switch (mode) {
    case Filter_LINEAR:                   return GL_LINEAR;
    case Filter_NEAREST:                  return GL_NEAREST;
    case Filter_LINEAR_MIPMAP_LINEAR:     return GL_LINEAR_MIPMAP_LINEAR;
    case Filter_LINEAR_MIPMAP_NEAREST:    return GL_LINEAR_MIPMAP_NEAREST;
    case Filter_NEAREST_MIPMAP_LINEAR:    return GL_NEAREST_MIPMAP_LINEAR;
    case Filter_NEAREST_MIPMAP_NEAREST:   return GL_NEAREST_MIPMAP_NEAREST;

    // CASE_CVT_GL(Filter_, LINEAR);
    // CASE_CVT_GL(Filter_, NEAREST);
    // CASE_CVT_GL(Filter_, LINEAR_MIPMAP_LINEAR);
    // CASE_CVT_GL(Filter_, LINEAR_MIPMAP_NEAREST);
    // CASE_CVT_GL(Filter_, NEAREST_MIPMAP_LINEAR);
    // CASE_CVT_GL(Filter_, NEAREST_MIPMAP_NEAREST);
    default:
      break;
  }
  return GL_NEAREST;
}

static inline GLint cvtCubeFace(CubeMapFace face) {
  switch (face) {
    case TEXTURE_CUBE_MAP_POSITIVE_X:     return GL_TEXTURE_CUBE_MAP_POSITIVE_X;
    case TEXTURE_CUBE_MAP_NEGATIVE_X:     return GL_TEXTURE_CUBE_MAP_NEGATIVE_X;
    case TEXTURE_CUBE_MAP_POSITIVE_Y:     return GL_TEXTURE_CUBE_MAP_POSITIVE_Y;
    case TEXTURE_CUBE_MAP_NEGATIVE_Y:     return GL_TEXTURE_CUBE_MAP_NEGATIVE_Y;
    case TEXTURE_CUBE_MAP_POSITIVE_Z:     return GL_TEXTURE_CUBE_MAP_POSITIVE_Z;
    case TEXTURE_CUBE_MAP_NEGATIVE_Z:     return GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;

    // CASE_CVT_GL(, TEXTURE_CUBE_MAP_POSITIVE_X);
    // CASE_CVT_GL(, TEXTURE_CUBE_MAP_NEGATIVE_X);
    // CASE_CVT_GL(, TEXTURE_CUBE_MAP_POSITIVE_Y);
    // CASE_CVT_GL(, TEXTURE_CUBE_MAP_NEGATIVE_Y);
    // CASE_CVT_GL(, TEXTURE_CUBE_MAP_POSITIVE_Z);
    // CASE_CVT_GL(, TEXTURE_CUBE_MAP_NEGATIVE_Z);
    default:
      break;
  }
  return 0;
}

static inline GLint cvtDepthFunc(DepthFunction func) {
  switch (func) {
    case DepthFunc_NEVER:                 return GL_NEVER;
    case DepthFunc_LESS:                  return GL_LESS;
    case DepthFunc_EQUAL:                 return GL_EQUAL;
    case DepthFunc_LEQUAL:                return GL_LEQUAL;
    case DepthFunc_GREATER:               return GL_GREATER;
    case DepthFunc_NOTEQUAL:              return GL_NOTEQUAL;
    case DepthFunc_GEQUAL:                return GL_GEQUAL;
    case DepthFunc_ALWAYS:                return GL_ALWAYS;

    // CASE_CVT_GL(DepthFunc_, NEVER);
    // CASE_CVT_GL(DepthFunc_, LESS);
    // CASE_CVT_GL(DepthFunc_, EQUAL);
    // CASE_CVT_GL(DepthFunc_, LEQUAL);
    // CASE_CVT_GL(DepthFunc_, GREATER);
    // CASE_CVT_GL(DepthFunc_, NOTEQUAL);
    // CASE_CVT_GL(DepthFunc_, GEQUAL);
    // CASE_CVT_GL(DepthFunc_, ALWAYS);
    default:
      break;
  }
  return 0;
}

static inline GLint cvtBlendFactor(BlendFactor factor) {
  switch (factor) {
    case BlendFactor_ZERO:                return GL_ZERO;
    case BlendFactor_ONE:                 return GL_ONE;
    case BlendFactor_SRC_COLOR:           return GL_SRC_COLOR;
    case BlendFactor_SRC_ALPHA:           return GL_SRC_ALPHA;
    case BlendFactor_DST_COLOR:           return GL_DST_COLOR;
    case BlendFactor_DST_ALPHA:           return GL_DST_ALPHA;
    case BlendFactor_ONE_MINUS_SRC_COLOR: return GL_ONE_MINUS_SRC_COLOR;
    case BlendFactor_ONE_MINUS_SRC_ALPHA: return GL_ONE_MINUS_SRC_ALPHA;
    case BlendFactor_ONE_MINUS_DST_COLOR: return GL_ONE_MINUS_DST_COLOR;
    case BlendFactor_ONE_MINUS_DST_ALPHA: return GL_ONE_MINUS_DST_ALPHA;

    // CASE_CVT_GL(BlendFactor_, ZERO);
    // CASE_CVT_GL(BlendFactor_, ONE);
    // CASE_CVT_GL(BlendFactor_, SRC_COLOR);
    // CASE_CVT_GL(BlendFactor_, SRC_ALPHA);
    // CASE_CVT_GL(BlendFactor_, DST_COLOR);
    // CASE_CVT_GL(BlendFactor_, DST_ALPHA);
    // CASE_CVT_GL(BlendFactor_, ONE_MINUS_SRC_COLOR);
    // CASE_CVT_GL(BlendFactor_, ONE_MINUS_SRC_ALPHA);
    // CASE_CVT_GL(BlendFactor_, ONE_MINUS_DST_COLOR);
    // CASE_CVT_GL(BlendFactor_, ONE_MINUS_DST_ALPHA);
    default:
      break;
  }
  return 0;
}

static inline GLint cvtBlendFunction(BlendFunction func) {
  switch (func) {
    case BlendFunc_ADD:                   return GL_FUNC_ADD;
    case BlendFunc_SUBTRACT:              return GL_FUNC_SUBTRACT;
    case BlendFunc_REVERSE_SUBTRACT:      return GL_FUNC_REVERSE_SUBTRACT;
    case BlendFunc_MIN:                   return GL_MIN;
    case BlendFunc_MAX:                   return GL_MAX;
    default:
      break;
  }
  return 0;
}

static inline GLint cvtPolygonMode(PolygonMode mode) {
  switch (mode) {
    case PolygonMode_POINT:               return GL_POINT;
    case PolygonMode_LINE:                return GL_LINE;
    case PolygonMode_FILL:                return GL_FILL;

    // CASE_CVT_GL(PolygonMode_, POINT);
    // CASE_CVT_GL(PolygonMode_, LINE);
    // CASE_CVT_GL(PolygonMode_, FILL);
    default:
      break;
  }
  return 0;
}

static inline GLint cvtDrawMode(PrimitiveType type) {
  switch (type) {
    case Primitive_POINT:                 return GL_POINTS;
    case Primitive_LINE:                  return GL_LINES;
    case Primitive_TRIANGLE:              return GL_TRIANGLES;
    default:
      break;
  }
  return 0;
}

static inline glm::vec4 cvtBorderColor(BorderColor color) {
  switch (color) {
    case Border_BLACK:                    return glm::vec4(0.f);
    case Border_WHITE:                    return glm::vec4(1.f);
    default:
      break;
  }
  return glm::vec4(0.f);
}

}
}
