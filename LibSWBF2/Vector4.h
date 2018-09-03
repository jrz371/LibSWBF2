#pragma once
#include "stdafx.h"
#include "Vector3.h"

namespace LibSWBF2
{
	struct Vector4 : public Vector3
	{
		Vector4();
		Vector4(const float_t& x, const float_t& y, const float_t& z, const float_t& w);
		~Vector4();

		void WriteToStream(ofstream& stream) override;
		void ReadFromStream(ifstream& stream) override;

		float_t w;
	};
}