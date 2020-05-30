#pragma once
#include "GenericChunk.h"

namespace LibSWBF2::Chunks
{
	struct LIBSWBF2_EXP STR : public GenericChunk
	{
		STR() = default;
		~STR() = default;

	public:
		String m_Text;

	public:
		void RefreshSize() override;
		void WriteToStream(FileWriter& stream) override;
		void ReadFromStream(FileReader& stream) override;

		String ToString() override;
	};
}