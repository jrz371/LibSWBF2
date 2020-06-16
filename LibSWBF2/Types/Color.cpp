#include "stdafx.h"
#include "Color.h"
#include "Logging\Logger.h"
#include "FileWriter.h"
#include "FileReader.h"
#include <algorithm>
#include <fmt/format.h>

namespace LibSWBF2::Types
{
	Color::Color() : Color(0, 0, 0, 1) { }
	Color::Color(const uint8_t Red, const uint8_t Green, const uint8_t Blue) : Color(Red, Green, Blue, 1) { }

	Color::Color(const uint8_t Red, const uint8_t Green, const uint8_t Blue, const uint8_t Alpha) :
		m_Red(std::clamp(m_Red, (uint8_t)0, (uint8_t)255)),
		m_Green(std::clamp(m_Green, (uint8_t)0, (uint8_t)255)),
		m_Blue(std::clamp(m_Blue, (uint8_t)0, (uint8_t)255)),
		m_Alpha(std::clamp(m_Alpha, (uint8_t)0, (uint8_t)255))
	{
		
	}

	Color::~Color()
	{
		
	}

	void Color::WriteToStream(FileWriter& stream)
	{
		// in LVL -> MTRL, color order is BGRA
		stream.WriteByte(m_Blue);
		stream.WriteByte(m_Green);
		stream.WriteByte(m_Red);
		stream.WriteByte(m_Alpha);
	}

	void Color::ReadFromStream(FileReader& stream)
	{
		// in LVL -> MTRL, color order is BGRA
		m_Blue = stream.ReadByte();
		m_Green = stream.ReadByte();
		m_Red = stream.ReadByte();
		m_Alpha = stream.ReadByte();
	}

	String Color::ToString()
	{
		return fmt::format("[R: {}, G: {}, B: {}, A: {}]", m_Red, m_Green, m_Blue, m_Alpha).c_str();
	}
}