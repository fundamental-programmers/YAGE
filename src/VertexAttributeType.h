#pragma once
#include "YageIncludes.h"

BEGIN_YAGE_NAMESPACE


enum VertexAttributeType
{
	VAT_Byte = GL_BYTE,
	VAT_UnsignedByte = GL_UNSIGNED_BYTE,
	VAT_Short = GL_SHORT,
	VAT_UnsignedShort = GL_UNSIGNED_SHORT,
	VAT_Int = GL_INT,
	VAT_UnsignedInt = GL_UNSIGNED_INT,
	VAT_HalfFloat = GL_HALF_FLOAT,
	VAT_Float = GL_FLOAT,
	VAT_Double = GL_DOUBLE,
	VAT_Fixed = GL_FIXED
};


END_YAGE_NAMESPACE