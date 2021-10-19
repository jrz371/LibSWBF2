#pragma once
#include "pch.h"
#include "Chunks/GenericChunk.h"
#include "Hashing.h"

namespace LibSWBF2::Chunks::LVL::sound
{
	template<uint32_t Header>
	struct LIBSWBF2_API SoundBaseChunk : public GenericChunk<Header>
	{
		void RefreshSize() override;
		void WriteToStream(FileWriter& stream) override;
		void ReadFromStream(FileReader& stream) override;

		Types::String ToString() const override;
	};

	struct LIBSWBF2_API SoundBaseChunkNC : public SoundBaseChunk<0> {};
}
