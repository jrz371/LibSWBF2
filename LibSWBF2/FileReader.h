#pragma once

namespace LibSWBF2
{
	using std::ifstream;

	class FileReader
	{
	public:
		FileReader();
		~FileReader();

		bool Open(const string& File);
		ChunkHeader ReadChunkHeader(const bool& peek);
		ChunkSize ReadChunkSize();
		uint8_t ReadByte();
		int32_t ReadInt32();
		uint32_t ReadUInt32();
		float_t ReadFloat();
		string ReadString(size_t length);
		size_t GetPosition();
		size_t GetFileSize();
		void Close();
	private:
		bool CheckGood(size_t ReadSize);

		size_t m_FileSize;
		string m_FileName;
		ifstream m_Reader;
	};
}
