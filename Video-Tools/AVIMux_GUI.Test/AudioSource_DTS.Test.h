#pragma once

#include "../Cache.h"
#include "../BitStreamFactory.h"
#include "../FileStream.h"
#include "../AVIMux_GUI/AudioSource_DTS.h"

using namespace System;
using namespace NUnit::Framework;

namespace AMG { namespace DTS 
{
	DTSSOURCE* GetDtsAudioSourceFromStream(STREAM* stream)
	{
		DTSSOURCE* result = new DTSSOURCE(stream);
		Assert::AreEqual((int)STREAM_OK, (int)result->Open(stream));
		return result;
	}

	DTSSOURCE* GetDtsAudioSourceFromFile(std::wstring fileName)
	{
		CFileStream* stream = new CFileStream();
		int openResult = stream->Open(fileName.c_str(), StreamMode::Read);
		Assert::AreEqual((int)STREAM_OK, openResult);

		return GetDtsAudioSourceFromStream(stream);
	}

	DTSSOURCE* GetDtsAudioSourceFromBuffer(const unsigned char* data, unsigned int size)
	{
		try
		{
			CMemoryStream* stream = CMemoryStream::Create(reinterpret_cast<const char*>(data), size);
			return GetDtsAudioSourceFromStream(stream);
		}
		catch (Object^)
		{
			return NULL;
		}
	}

	void CloseDTSAudioSource(DTSSOURCE* dts)
	{
		dts->GetSource()->Close();
		delete dts->GetSource();
		dts->Close();
		delete dts;
	}


	// Erste Frame der Datei: Sunshine-DE-1000blocks.dts
	static unsigned char testdata_sunshine_de_6ch_48khz_1024bpf_10666666nspf[] = {
		0x7F, 0xFE, 0x80, 0x01, 0xFC, 0x3C, 0x3F, 0xF2, 0x75, 0xE0, 0x05, 0x3B, 0x80, 0x09, 0x8C, 0x63, 0x18, 
		0x9C, 0xE7, 0x39, 0x80, 0x00, 0xFF, 0xED, 0xB6, 0xDB, 0x6D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC2, 
		0x22, 0xA8, 0x64, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0xA8, 0x64, 0x22, 0x22, 0x22, 0x22, 
		0x22, 0x22, 0x22, 0x22, 0xA8, 0x64, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0xA8, 0x64, 0x22, 
		0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x37, 0xC8, 0x6F, 0x90, 0xCD, 0x06, 0x68,
		0x25, 0x82, 0x58, 0x27, 0x09, 0xC2, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 
		0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x43, 
		0x7C, 0x86, 0xF9, 0x0C, 0xD0, 0x66, 0x82, 0x58, 0x25, 0x82, 0x70, 0x9C, 0x28, 0x50, 0xA1, 0x42, 0x85, 
		0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 
		0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x37, 0xC8, 0x6F, 0x90, 0xCD, 0x06, 0x68, 0x25, 0x82, 0x58, 0x27, 
		0x09, 0xC2, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 
		0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x43, 0x7C, 0x86, 0xF9, 0x0C, 
		0xD0, 0x66, 0x82, 0x58, 0x25, 0x82, 0x70, 0x9C, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 
		0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 
		0x0A, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0D, 0xF2, 0x1B, 0xE4, 0x33, 0x41, 0x9A, 0x09, 0x60, 0x96, 0x09, 
		0xC2, 0x70, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 
		0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xDF, 0x21, 0xBE, 0x43, 
		0x34, 0x19, 0xA0, 0x96, 0x09, 0x60, 0x9C, 0x27, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 
		0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 
		0x42, 0x85, 0x0D, 0xF2, 0x1B, 0xE4, 0x33, 0x41, 0x9A, 0x09, 0x60, 0x96, 0x09, 0xC2, 0x70, 0xA1, 0x42,
		0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14,
		0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xDF, 0x21, 0xBE, 0x43, 0x34, 0x19, 0xA0, 0x96, 
		0x09, 0x60, 0x9C, 0x27, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 
		0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x1F, 0xFF, 
		0xE0, 0x00, 0x00, 0x00
	};

	// // Erste Frame der Datei: Sunshine-en-1000blocks.dts
	static unsigned char testdata_sunshine_en_6ch_48khz_2012bpf_10666666nspf[] = {
		0x7F, 0xFE, 0x80, 0x01, 0xFC, 0x3C, 0x7D, 0xB2, 0x77, 0x00, 0x0D, 0x3B, 0x80, 0x09, 0xEF, 0x7B, 0xDE, 
		0xDE, 0xF7, 0xBD, 0x80, 0x00, 0xFF, 0xF6, 0xDB, 0x6D, 0xB6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x31, 0x8C, 0x63, 0x18, 0xC6, 
		0x31, 0x8C, 0x63, 0x18, 0xC6, 0x31, 0x8C, 0x63, 0x18, 0xC6, 0x31, 0x8C, 0x20, 0xC5, 0x18, 0x82, 0x10, 
		0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x09, 0xCC, 0x51, 0x88, 0x21, 
		0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x9C, 0xC5, 0x18, 0x82,
		0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x09, 0xCC, 0x51, 0x88, 
		0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x84, 0x21, 0x08, 0x42, 0x10, 0x80, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x28, 0xC8, 0x14, 0x64, 0x0D, 0xF2, 0x1B, 0xE4, 0x25, 0x82, 0x58, 0x27, 0x09, 0xC2, 0x85, 0x0A, 0x14, 
		0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 
		0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 
		0x14, 0x28, 0x50, 0xBE, 0xBC, 0x17, 0xD7, 0x82, 0x8C, 0x81, 0x46, 0x40, 0xDF, 0x21, 0xBE, 0x42, 0x58, 
		0x25, 0x82, 0x70, 0x9C, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A,
		0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50,
		0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0B, 0xEB, 0xC1, 0x7D, 0x78, 0x28, 0xC8,
		0x14, 0x64, 0x0D, 0xF2, 0x1B, 0xE4, 0x25, 0x82, 0x58, 0x27, 0x09, 0xC2, 0x85, 0x0A, 0x14, 0x28, 0x50,
		0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85,
		0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28,
		0x50, 0xBE, 0xBC, 0x17, 0xD7, 0x82, 0x8C, 0x81, 0x46, 0x40, 0xDF, 0x21, 0xBE, 0x42, 0x58, 0x25, 0x82,
		0x70, 0x9C, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28,
		0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 
		0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x1F, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x32, 0x05, 0x19, 0x03, 0x7C, 0x86, 0xF9, 0x09, 
		0x60, 0x96, 0x09, 0xC2, 0x70, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14,
		0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1,
		0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x2F, 0xAF, 0x05, 0xF5, 0xE0, 0xA3,
		0x20, 0x51, 0x90, 0x37, 0xC8, 0x6F, 0x90, 0x96, 0x09, 0x60, 0x9C, 0x27, 0x0A, 0x14, 0x28, 0x50, 0xA1,
		0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A,
		0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 
		0xA1, 0x42, 0xFA, 0xF0, 0x5F, 0x5E, 0x0A, 0x32, 0x05, 0x19, 0x03, 0x7C, 0x86, 0xF9, 0x09, 0x60, 0x96, 
		0x09, 0xC2, 0x70, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 
		0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85,
		0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x2F, 0xAF, 0x05, 0xF5, 0xE0, 0xA3, 0x20, 0x51,
		0x90, 0x37, 0xC8, 0x6F, 0x90, 0x96, 0x09, 0x60, 0x9C, 0x27, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85,
		0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 
		0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x42, 0x85, 0x0A, 0x14, 0x28, 0x50, 0xA1, 0x47, 
		0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00
	};


	
	[TestFixture]
	public ref class Test_DTS_Reader_with_Sunshine_de_1000blocks 
	{
	private:

	public:
		[Test]
		void Test_Open()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_de_6ch_48khz_1024bpf_10666666nspf, 1024);
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_GetChannelCount()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_de_6ch_48khz_1024bpf_10666666nspf, 1024);
			Assert::AreEqual((int)6, dts->GetChannelCount());
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_GetFrameSize()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_de_6ch_48khz_1024bpf_10666666nspf, 1024);
			Assert::AreEqual((int)1024, dts->GetFrameSize());
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_GetFrameDuration()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_de_6ch_48khz_1024bpf_10666666nspf, 1024);
			Assert::AreEqual((__int64)10666666, dts->GetFrameDuration());
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_GetBytePerSecond()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_de_6ch_48khz_1024bpf_10666666nspf, 1024);
			int avgbps = dts->GetAvgBytesPerSec();
			Assert::AreEqual((int)94312, avgbps);
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_ReadFrame()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_de_6ch_48khz_1024bpf_10666666nspf, 1024);
			dts->SetFrameMode(1);
			MULTIMEDIA_DATA_PACKET* packet = NULL;
			DWORD dwRead = dts->Read(&packet);
			CloseDTSAudioSource(dts);

			Assert::AreEqual((int)1024, (int)dwRead);
			Assert::AreEqual((int)10666666, (int)packet->duration);
			freeMultimediaDataPacket(packet);
		}

		[Test]
		void Test_ReadFrame_old()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_de_6ch_48khz_1024bpf_10666666nspf, 1024);
			dts->SetFrameMode(1);

			char buffer[1024];
			__int64 nsRead;
			__int64 timeCode;
			DWORD dwRead = dts->Read(buffer, 1, NULL, &nsRead, &timeCode, NULL);

			CloseDTSAudioSource(dts);

			Assert::AreEqual((int)1024, (int)dwRead);
			Assert::AreEqual((int)10666666, (int)nsRead);
		}
	};


	[TestFixture]
	public ref class Test_DTS_Reader_with_Sunshine_en_1000blocks 
	{
	private:

	public:
		[Test]
		void Test_Open()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_en_6ch_48khz_2012bpf_10666666nspf, 2012);
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_GetChannelCount()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_en_6ch_48khz_2012bpf_10666666nspf, 2012);
			Assert::AreEqual((int)6, dts->GetChannelCount());
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_GetFrameSize()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_en_6ch_48khz_2012bpf_10666666nspf, 2012);
			Assert::AreEqual((int)2012, dts->GetFrameSize());
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_GetFrameDuration()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_en_6ch_48khz_2012bpf_10666666nspf, 2012);
			Assert::AreEqual((__int64)10666666, dts->GetFrameDuration());
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_GetBytePerSecond()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_en_6ch_48khz_2012bpf_10666666nspf, 2012);
			int avgbps = dts->GetAvgBytesPerSec();
			Assert::AreEqual((int)188718, avgbps);
			CloseDTSAudioSource(dts);
		}

		[Test]
		void Test_ReadFrame()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_en_6ch_48khz_2012bpf_10666666nspf, 2012);
			dts->SetFrameMode(1);
			MULTIMEDIA_DATA_PACKET* packet = NULL;
			DWORD dwRead = dts->Read(&packet);

			CloseDTSAudioSource(dts);

			Assert::AreEqual((int)2012, (int)dwRead);
			Assert::AreEqual((int)10666666, (int)packet->duration);
			freeMultimediaDataPacket(packet);
		}

		[Test]
		void Test_ReadFrame_old()
		{
			DTSSOURCE* dts = GetDtsAudioSourceFromBuffer(testdata_sunshine_en_6ch_48khz_2012bpf_10666666nspf, 2012);
			dts->SetFrameMode(1);

			char buffer[2012];
			__int64 nsRead;
			__int64 timeCode;
			DWORD dwRead = dts->Read(buffer, 1, NULL, &nsRead, &timeCode, NULL);

			CloseDTSAudioSource(dts);

			Assert::AreEqual((int)2012, (int)dwRead);
			Assert::AreEqual((int)10666666, (int)nsRead);
		}
	};
}}