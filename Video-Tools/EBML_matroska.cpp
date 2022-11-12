#include "stdafx.h"
#include "EBML.h"
#include "EBML_matroska.h"
#include "Matroska_IDs.h"
#include "Matroska_Segment.h"
#include "Matroska_Block.h"

#include "Warnings.h"

#ifdef DEBUG_NEW
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

#define MATR_CONSTR(a,i,m,c) \
	a::a(STREAM* s,EBMLElement* p) \
	{ \
		SetStream(s); \
		SetParent(p); \
		DetermineLength(); \
		SetType(i); \
		SetMulti(m); \
		SetDataType(c); \
		return; \
	} 

#define MATR_TYPENAME(a,s) \
	char* a::GetTypeString() \
	{ \
	    return s; \
	}

#define DEF_MATR_CLASS(a,i,m,c,s) \
	MATR_CONSTR(a,i,m,c); \
	MATR_TYPENAME(a,s);


EBML_Matroska::EBML_Matroska()
{
	SetParent(NULL);
	SetStream(NULL);
	SetMulti(false);
	SetType(ETM_FILE);
	return;
}

EBML_Matroska::EBML_Matroska(STREAM* s,EBMLElement* p)
{
	SetParent(p);
	SetStream(s);
	SetMulti(false);
	SetType(ETM_FILE);
	SetElementLength(s->GetSize());
	SetDataType(EBMLDATATYPE_MASTER);
	return;
}

bool EBML_Matroska::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_SEGMENT,EBMLM_Segment)
	DOCOMPL(EID_EBML,EBML_EBML)
}

EBML_MatroskaElement::EBML_MatroskaElement()
{
}

__int64 EBML_MatroskaElement::AsInt()
{
	return (GetData()->AsBSWInt());
}

__int64 EBML_MatroskaElement::AsSInt()
{
	return (GetData()->AsSBSWInt());
}

double EBML_MatroskaElement::AsFloat()
{
	return (GetData()->AsBSWFloat());
}

bool EBML_MatroskaElement::CheckGlobalIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_VOID,EBMLM_Void)
	DOCOMPL(MID_CRC32,EBMLM_CRC32)
}



///////////////////////
// Matroska-Seekhead //
///////////////////////
DEF_MATR_CLASS(EBMLM_Seekhead,IDVALUE(MID_SEEKHEAD),true,true,"Seekhead");

bool EBMLM_Seekhead::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMPL(MID_MS_SEEK,EBMLM_Seek)
}

// multi=0 / Daten-Typ

DEF_MATR_CLASS(EBMLM_SIInfo,IDVALUE(MID_SEGMENTINFO),true,true,"SegmentInfo");
DEF_MATR_CLASS(EBMLM_SISegmentUID,ETM_SI_SEGMENTUID,false,EBMLDATATYPE_HEX,"SegmentUID");
DEF_MATR_CLASS(EBMLM_SISegmentFamily,IDVALUE(MID_SI_SEGMENTFAMILY),false,EBMLDATATYPE_HEX,"SegmentFamily");
DEF_MATR_CLASS(EBMLM_SISegmentFilename,ETM_SI_SEGMENTFILENAME,false,EBMLDATATYPE_ASCII,"SegmentFilename");
DEF_MATR_CLASS(EBMLM_SIPrevUID,ETM_SI_PREVUID,false,EBMLDATATYPE_HEX,"PrevUID");
DEF_MATR_CLASS(EBMLM_SIPrevFilename,ETM_SI_PREVFILENAME,false,EBMLDATATYPE_ASCII,"PrevFilename");
DEF_MATR_CLASS(EBMLM_SINextUID,ETM_SI_NEXTUID,false,EBMLDATATYPE_HEX,"NextUID");
DEF_MATR_CLASS(EBMLM_SINextFilename,ETM_SI_NEXTFILENAME,false,EBMLDATATYPE_ASCII,"NextFilename");
DEF_MATR_CLASS(EBMLM_SITimecodeScale,ETM_SI_TIMECODESCALE,false,EBMLDATATYPE_INT,"TimecodeScale");
DEF_MATR_CLASS(EBMLM_SIDuration,ETM_SI_DURATION,false,EBMLDATATYPE_FLOAT,"Duration");
DEF_MATR_CLASS(EBMLM_SIDateUTC,ETM_SI_DATEUTC,false,EBMLDATATYPE_INT,"DateUTC");
DEF_MATR_CLASS(EBMLM_SITitle,ETM_SI_TITLE,false,EBMLDATATYPE_UTF8,"Title");
DEF_MATR_CLASS(EBMLM_SIMuxingApp,ETM_SI_MUXINGAPP,false,EBMLDATATYPE_ASCII,"MuxingApp");
DEF_MATR_CLASS(EBMLM_SIWritingApp,ETM_SI_WRITINGAPP,false,EBMLDATATYPE_ASCII,"WritingApp");

bool EBMLM_SIInfo::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_SI_SEGMENTUID,EBMLM_SISegmentUID)
	DOCOMP(MID_SI_SEGMENTFAMILY,EBMLM_SISegmentFamily)
	DOCOMP(MID_SI_SEGMENTFILENAME,EBMLM_SISegmentFilename)
	DOCOMP(MID_SI_PREVUID,EBMLM_SIPrevUID)
	DOCOMP(MID_SI_PREVFILENAME,EBMLM_SIPrevFilename)
	DOCOMP(MID_SI_NEXTUID,EBMLM_SINextUID)
	DOCOMP(MID_SI_NEXTFILENAME,EBMLM_SINextFilename)
	DOCOMP(MID_SI_TIMECODESCALE,EBMLM_SITimecodeScale)
	DOCOMP(MID_SI_DURATION,EBMLM_SIDuration)
	DOCOMP(MID_SI_DATEUTC,EBMLM_SIDateUTC)
	DOCOMP(MID_SI_TITLE,EBMLM_SITitle)
	DOCOMP(MID_SI_MUXINGAPP,EBMLM_SIMuxingApp)
	DOCOMPL(MID_SI_WRITINGAPP,EBMLM_SIWritingApp)
}


DEF_MATR_CLASS(EBMLM_Tracks,IDVALUE(MID_TRACKS),true,true,"Tracks");

bool EBMLM_Tracks::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMPL(MID_TR_TRACKENTRY,EBMLM_TRTrackEntry)
}

DEF_MATR_CLASS(EBMLM_TRTrackEntry,IDVALUE(MID_TR_TRACKENTRY),true,true,"TrackEntry");

bool EBMLM_TRTrackEntry::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_TR_TRACKNUMBER,EBMLM_TRTrackNumber)
	DOCOMP(MID_TR_TRACKUID,EBMLM_TRTrackUID)
	DOCOMP(MID_TR_TRACKTYPE,EBMLM_TRTrackType)
	DOCOMP(MID_TR_FLAGENABLED,EBMLM_TRFlagEnabled)
	DOCOMP(MID_TR_FLAGDEFAULT,EBMLM_TRFlagDefault)
	DOCOMP(MID_TR_FLAGLACING,EBMLM_TRFlagLacing)
	DOCOMP(MID_TR_FLAGFORCED,EBMLM_TRFlagForced)
	DOCOMP(MID_TR_MINCACHE,EBMLM_TRMinCache)
	DOCOMP(MID_TR_MAXCACHE,EBMLM_TRMaxCache)
	DOCOMP(MID_TR_TRACKOFFSET,EBMLM_TRTrackOffset)
	DOCOMP(MID_TR_DEFAULTDURATION,EBMLM_TRDefaultDuration)
	DOCOMP(MID_TR_TRACKTIMECODESCALE,EBMLM_TRTrackTimeCodeScale)
	DOCOMP(MID_TR_NAME,EBMLM_TRName)
	DOCOMP(MID_TR_LANGUAGE,EBMLM_TRLanguage)
	DOCOMP(MID_TR_CODECID,EBMLM_TRCodecID)
	DOCOMP(MID_TR_CODECPRIVATE,EBMLM_TRCodecPrivate)
	DOCOMP(MID_TR_CODECNAME,EBMLM_TRCodecName)
	DOCOMP(MID_TR_CODECSETTINGS,EBMLM_TRCodecSettings)
	DOCOMP(MID_TR_CODECINFOURL,EBMLM_TRCodecInfoURL)
	DOCOMP(MID_TR_CODECDOWNLOADURL,EBMLM_TRCodecDownloadURL)
	DOCOMP(MID_TR_CODECDECODEALL,EBMLM_TRCodecDecodeAll)
	DOCOMP(MID_TR_TRACKOVERLAY,EBMLM_TRTrackOverlay)
	DOCOMP(MID_TR_VIDEO,EBMLM_TRVideo)
	DOCOMP(MID_TR_SAMPLESCALE,EBMLM_TRSampleScale)
	DOCOMP(MID_TR_MAXBLOCKADDITIONID,EBMLM_TRMaxBlockAdditionID)
	DOCOMP(MID_TR_CONTENTENCODINGS, EBMLM_TRContentEncodings)
	DOCOMPL(MID_TR_AUDIO,EBMLM_TRAudio)
}

DEF_MATR_CLASS(EBMLM_TRTrackNumber,IDVALUE(MID_TR_TRACKNUMBER),false,EBMLDATATYPE_INT,"TrackNumber");
DEF_MATR_CLASS(EBMLM_TRTrackUID,IDVALUE(MID_TR_TRACKUID),false,EBMLDATATYPE_HEX,"TrackUID");
DEF_MATR_CLASS(EBMLM_TRTrackType,IDVALUE(MID_TR_TRACKTYPE),false,EBMLDATATYPE_INT,"TrackType");
DEF_MATR_CLASS(EBMLM_TRFlagEnabled,IDVALUE(MID_TR_FLAGENABLED),false,EBMLDATATYPE_INT,"FlagEnabled");
DEF_MATR_CLASS(EBMLM_TRFlagDefault,IDVALUE(MID_TR_FLAGDEFAULT),false,EBMLDATATYPE_INT,"FlagDefault");
DEF_MATR_CLASS(EBMLM_TRFlagLacing,IDVALUE(MID_TR_FLAGLACING),false,EBMLDATATYPE_INT,"FlagLacing");
DEF_MATR_CLASS(EBMLM_TRFlagForced,IDVALUE(MID_TR_FLAGFORCED),false,EBMLDATATYPE_INT,"FlagForced");
DEF_MATR_CLASS(EBMLM_TRMinCache,IDVALUE(MID_TR_MINCACHE),false,EBMLDATATYPE_INT,"MinCache");
DEF_MATR_CLASS(EBMLM_TRMaxCache,IDVALUE(MID_TR_MAXCACHE),false,EBMLDATATYPE_INT,"MaxCache");
DEF_MATR_CLASS(EBMLM_TRTrackOffset,IDVALUE(MID_TR_TRACKOFFSET),false,EBMLDATATYPE_SINT,"TrackOffset");
DEF_MATR_CLASS(EBMLM_TRDefaultDuration,IDVALUE(MID_TR_DEFAULTDURATION),false,EBMLDATATYPE_INT,"DefaultDuration");
DEF_MATR_CLASS(EBMLM_TRTrackTimeCodeScale,ETM_TR_TRACKTIMECODESCALE,false,EBMLDATATYPE_FLOAT,"TrackTimeCodeScale");
DEF_MATR_CLASS(EBMLM_TRName,ETM_TR_NAME,false,EBMLDATATYPE_UTF8,"Name");
DEF_MATR_CLASS(EBMLM_TRLanguage,ETM_TR_LANGUAGE,false,EBMLDATATYPE_ASCII,"Language");
DEF_MATR_CLASS(EBMLM_TRCodecID,ETM_TR_CODECID,false,EBMLDATATYPE_ASCII,"CodecID");
DEF_MATR_CLASS(EBMLM_TRCodecPrivate,ETM_TR_CODECPRIVATE,false,EBMLDATATYPE_BIN,"CodecPrivate");
DEF_MATR_CLASS(EBMLM_TRCodecName,ETM_TR_CODECNAME,false,EBMLDATATYPE_ASCII,"CodecName");
DEF_MATR_CLASS(EBMLM_TRCodecSettings,ETM_TR_CODECSETTINGS,false,EBMLDATATYPE_UTF8,"CodecSettings");
DEF_MATR_CLASS(EBMLM_TRCodecInfoURL,ETM_TR_CODECINFOURL,false,EBMLDATATYPE_ASCII,"CodecInfoURL");
DEF_MATR_CLASS(EBMLM_TRCodecDownloadURL,ETM_TR_CODECDOWNLOADURL,false,EBMLDATATYPE_ASCII,"CodecDownloadURL");
DEF_MATR_CLASS(EBMLM_TRCodecDecodeAll,ETM_TR_CODECDECODEALL,false,EBMLDATATYPE_INT,"CodecDecodeAll");
DEF_MATR_CLASS(EBMLM_TRTrackOverlay,ETM_TR_TRACKOVERLAY,false,EBMLDATATYPE_INT,"TrackOverlay");
DEF_MATR_CLASS(EBMLM_TRSampleScale,ETM_TR_SAMPLESCALE,false,EBMLDATATYPE_INT,"SampleScale");
DEF_MATR_CLASS(EBMLM_TRMaxBlockAdditionID,IDVALUE(MID_TR_MAXBLOCKADDITIONID),false,EBMLDATATYPE_INT,"MaxBlockAdditionID");
DEF_MATR_CLASS(EBMLM_TRVideo,ETM_TR_VIDEO,false,true,"TrackVideo");
DEF_MATR_CLASS(EBMLM_TRAudio,ETM_TR_AUDIO,false,true,"TrackAudio");
DEF_MATR_CLASS(EBMLM_TRContentEncodings,ETM_TR_CONTENTENCODINGS,false,true,"ContentEncodings");
DEF_MATR_CLASS(EBMLM_TRCEContentEncoding,IDVALUE(MID_TRCE_CONTENTENCODING),true,true,"ContentEncoding");
DEF_MATR_CLASS(EBMLM_TRCEContentEncodingOrder, IDVALUE(MID_TRCE_CONTENTENCODINGORDER),false,EBMLDATATYPE_INT,"ContentEncodingOrder");
DEF_MATR_CLASS(EBMLM_TRCEContentEncodingScope, IDVALUE(MID_TRCE_CONTENTENCODINGSCOPE),false,EBMLDATATYPE_INT,"ContentEncodingScope");
DEF_MATR_CLASS(EBMLM_TRCEContentEncodingType, IDVALUE(MID_TRCE_CONTENTENCODINGTYPE),false,EBMLDATATYPE_INT,"ContentEncodingType");
DEF_MATR_CLASS(EBMLM_TRCEContentCompression, IDVALUE(MID_TRCE_CONTENTCOMPRESSION),true,true,"ContentCompression");
DEF_MATR_CLASS(EBMLM_TRCEContentCompAlgo, IDVALUE(MID_TRCE_CONTENTCOMPALGO),false,EBMLDATATYPE_INT,"ContentCompAlgo");
DEF_MATR_CLASS(EBMLM_TRCEContentCompressionSettings, IDVALUE(MID_TRCE_CONTENTCOMPSETTINGS),true,EBMLDATATYPE_HEX,"ContentCompSettings");

bool EBMLM_TRContentEncodings::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMPL(MID_TRCE_CONTENTENCODING,EBMLM_TRCEContentEncoding)
}
bool EBMLM_TRCEContentEncoding::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_TRCE_CONTENTENCODINGORDER,EBMLM_TRCEContentEncodingOrder)
	DOCOMP(MID_TRCE_CONTENTENCODINGSCOPE,EBMLM_TRCEContentEncodingScope)
	DOCOMP(MID_TRCE_CONTENTENCODINGTYPE,EBMLM_TRCEContentEncodingType)
	DOCOMPL(MID_TRCE_CONTENTCOMPRESSION,EBMLM_TRCEContentCompression)
}
bool EBMLM_TRCEContentCompression::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_TRCE_CONTENTCOMPALGO,EBMLM_TRCEContentCompAlgo)
	DOCOMPL(MID_TRCE_CONTENTCOMPSETTINGS,EBMLM_TRCEContentCompressionSettings)

}

bool EBMLM_TRVideo::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_TRV_FLAGINTERLACED,EBMLM_TRVFlagInterlaced)
	DOCOMP(MID_TRV_STEREOMODE,EBMLM_TRVStereoMode)
	DOCOMP(MID_TRV_PIXELWIDTH,EBMLM_TRVPixelWidth)
	DOCOMP(MID_TRV_PIXELHEIGHT,EBMLM_TRVPixelHeight)
	DOCOMP(MID_TRV_PIXELCROPLEFT, EBMLM_TRVPixelCropLeft)
	DOCOMP(MID_TRV_PIXELCROPRIGHT, EBMLM_TRVPixelCropRight)
	DOCOMP(MID_TRV_PIXELCROPTOP, EBMLM_TRVPixelCropTop)
	DOCOMP(MID_TRV_PIXELCROPBOTTOM, EBMLM_TRVPixelCropBottom)

	DOCOMP(MID_TRV_DISPLAYWIDTH,EBMLM_TRVDisplayWidth)
	DOCOMP(MID_TRV_DISPLAYHEIGHT,EBMLM_TRVDisplayHeight)
	DOCOMP(MID_TRV_DISPLAYUNIT,EBMLM_TRVDisplayUnit)
	DOCOMP(MID_TRV_ASPECTRATIO,EBMLM_TRVAspectRatioType)
	DOCOMP(MID_TRV_COLORSPACE,EBMLM_TRVColourSpace)
	DOCOMPL(MID_TRV_GAMMAVALUE,EBMLM_TRVGammaValue)
}
bool EBMLM_TRAudio::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_TRA_SAMPLINGFREQUENCY,EBMLM_TRASamplingFrequency)
	DOCOMP(MID_TRA_OUTPUTSAMPLINGFREQUENCY,EBMLM_TRAOutputSamplingFrequency)
	DOCOMP(MID_TRA_CHANNELS,EBMLM_TRAChannels)
	DOCOMP(MID_TRA_CHANNELPOSITIONS,EBMLM_TRAChannelPositions)
	DOCOMPL(MID_TRA_BITDEPTH,EBMLM_TRABitDepth)
}

DEF_MATR_CLASS(EBMLM_TRVFlagInterlaced,IDVALUE(MID_TRV_FLAGINTERLACED),false,EBMLDATATYPE_INT,"FlagInterlaced");
DEF_MATR_CLASS(EBMLM_TRVStereoMode,IDVALUE(MID_TRV_STEREOMODE),false,EBMLDATATYPE_INT,"StereoMode");
DEF_MATR_CLASS(EBMLM_TRVPixelWidth,IDVALUE(MID_TRV_PIXELWIDTH),false,EBMLDATATYPE_INT,"PixelWidth");
DEF_MATR_CLASS(EBMLM_TRVPixelHeight,IDVALUE(MID_TRV_PIXELHEIGHT),false,EBMLDATATYPE_INT,"PixelHeight");
DEF_MATR_CLASS(EBMLM_TRVPixelCropLeft,IDVALUE(MID_TRV_PIXELCROPLEFT),false,EBMLDATATYPE_INT,"PixelCropLeft");
DEF_MATR_CLASS(EBMLM_TRVPixelCropRight,IDVALUE(MID_TRV_PIXELCROPRIGHT),false,EBMLDATATYPE_INT,"PixelCropRight");
DEF_MATR_CLASS(EBMLM_TRVPixelCropTop,IDVALUE(MID_TRV_PIXELCROPTOP),false,EBMLDATATYPE_INT,"PixelCropTop");
DEF_MATR_CLASS(EBMLM_TRVPixelCropBottom,IDVALUE(MID_TRV_PIXELCROPBOTTOM),false,EBMLDATATYPE_INT,"PixelCropBottom");

DEF_MATR_CLASS(EBMLM_TRVDisplayWidth,IDVALUE(MID_TRV_DISPLAYWIDTH),false,EBMLDATATYPE_INT,"DisplayWidth");
DEF_MATR_CLASS(EBMLM_TRVDisplayHeight,IDVALUE(MID_TRV_DISPLAYHEIGHT),false,EBMLDATATYPE_INT,"DisplayHeight");
DEF_MATR_CLASS(EBMLM_TRVDisplayUnit,IDVALUE(MID_TRV_DISPLAYUNIT),false,EBMLDATATYPE_INT,"DisplayUnit");
DEF_MATR_CLASS(EBMLM_TRVAspectRatioType,IDVALUE(MID_TRV_ASPECTRATIO),false,EBMLDATATYPE_INT,"AspectRatioType");
DEF_MATR_CLASS(EBMLM_TRVColourSpace,IDVALUE(MID_TRV_COLORSPACE),false,EBMLDATATYPE_ASCII,"ColourSpace");
DEF_MATR_CLASS(EBMLM_TRVGammaValue,IDVALUE(MID_TRV_GAMMAVALUE),false,EBMLDATATYPE_FLOAT,"GammaValue");
DEF_MATR_CLASS(EBMLM_TRASamplingFrequency,IDVALUE(MID_TRA_SAMPLINGFREQUENCY),false,EBMLDATATYPE_FLOAT,"SamplingFrequency");
DEF_MATR_CLASS(EBMLM_TRAOutputSamplingFrequency,IDVALUE(MID_TRA_OUTPUTSAMPLINGFREQUENCY),false,EBMLDATATYPE_FLOAT,"OutputSamplingFrequency");
DEF_MATR_CLASS(EBMLM_TRAChannels,IDVALUE(MID_TRA_CHANNELS),false,EBMLDATATYPE_INT,"Channels");
DEF_MATR_CLASS(EBMLM_TRAChannelPositions,IDVALUE(MID_TRA_CHANNELPOSITIONS),false,EBMLDATATYPE_BIN,"ChannelPosition");
DEF_MATR_CLASS(EBMLM_TRABitDepth,IDVALUE(MID_TRA_BITDEPTH),false,EBMLDATATYPE_INT,"BitDepth");


DEF_MATR_CLASS(EBMLM_Cues,IDVALUE(MID_CUES),false,true,"Cues");
bool EBMLM_Cues::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMPL(MID_CU_CUEPOINT,EBMLM_CUCuePoint)
}
DEF_MATR_CLASS(EBMLM_CUCuePoint,IDVALUE(MID_CU_CUEPOINT),true,true,"CuePoint");
bool EBMLM_CUCuePoint::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CU_CUETIME,EBMLM_CUCueTime)
	DOCOMPL(MID_CU_CUETRACKPOSITIONS,EBMLM_CUCueTrackPositions)
}

DEF_MATR_CLASS(EBMLM_CUCueTime,IDVALUE(MID_CU_CUETIME),false,EBMLDATATYPE_INT,"CueTime");
DEF_MATR_CLASS(EBMLM_CUCueTrackPositions,IDVALUE(MID_CU_CUETRACKPOSITIONS),true,true,"CueTrackPosition");
bool EBMLM_CUCueTrackPositions::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CU_CUETRACK,EBMLM_CUCueTrack)
	DOCOMP(MID_CU_CUECLUSTERPOSITION,EBMLM_CUCueClusterPosition)
	DOCOMP(MID_CU_CUEBLOCKNUMBER,EBMLM_CUCueBlockNumber)
	DOCOMP(MID_CU_CUECODECSTATE,EBMLM_CUCueCodecState)
	DOCOMPL(MID_CU_CUEREFERENCE,EBMLM_CUCueReference)
}
DEF_MATR_CLASS(EBMLM_CUCueTrack,IDVALUE(MID_CU_CUETRACK),false,EBMLDATATYPE_INT,"CueTrack");
DEF_MATR_CLASS(EBMLM_CUCueClusterPosition,IDVALUE(MID_CU_CUECLUSTERPOSITION),false,EBMLDATATYPE_INT,"CueClusterPosition");
DEF_MATR_CLASS(EBMLM_CUCueBlockNumber,IDVALUE(MID_CU_CUEBLOCKNUMBER),false,EBMLDATATYPE_INT,"CueBlockNumber");
DEF_MATR_CLASS(EBMLM_CUCueCodecState,IDVALUE(MID_CU_CUECODECSTATE),false,EBMLDATATYPE_INT,"CueCodecState");

DEF_MATR_CLASS(EBMLM_CUCueReference,IDVALUE(MID_CU_CUEREFERENCE),true,true,"CueReference");
bool EBMLM_CUCueReference::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CU_CUEREFTIME,EBMLM_CUCueRefTime)
	DOCOMP(MID_CU_CUEREFCLUSTER,EBMLM_CUCueRefCluster)
	DOCOMP(MID_CU_CUEREFNUMBER,EBMLM_CUCueRefNumber)
	DOCOMPL(MID_CU_CUEREFCODECSTATE,EBMLM_CUCueRefCodecState)
}
DEF_MATR_CLASS(EBMLM_CUCueRefTime,IDVALUE(MID_CU_CUEREFTIME),false,EBMLDATATYPE_INT,"CueRefTime");
DEF_MATR_CLASS(EBMLM_CUCueRefCluster,IDVALUE(MID_CU_CUEREFCLUSTER),false,EBMLDATATYPE_INT,"CueRefCluster");
DEF_MATR_CLASS(EBMLM_CUCueRefNumber,IDVALUE(MID_CU_CUEREFNUMBER),false,EBMLDATATYPE_INT,"CueRefNumber");
DEF_MATR_CLASS(EBMLM_CUCueRefCodecState,IDVALUE(MID_CU_CUEREFCODECSTATE),false,EBMLDATATYPE_INT,"CueRefCodecState");

DEF_MATR_CLASS(EBMLM_Attachments,IDVALUE(MID_ATTACHMENTS),false,true,"Attachments");
bool EBMLM_Attachments::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMPL(MID_AT_ATTACHEDFILE,EBMLM_ATAttachedFile)
}
DEF_MATR_CLASS(EBMLM_ATAttachedFile,IDVALUE(MID_AT_ATTACHEDFILE),true,true,"AttachedFile");
bool EBMLM_ATAttachedFile::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_AT_FILEDESCRIPTION,EBMLM_ATFileDescription)
	DOCOMP(MID_AT_FILENAME,EBMLM_ATFileName)
	DOCOMP(MID_AT_FILEMIMETYPE,EBMLM_ATFileMimeType)
	DOCOMP(MID_AT_FILEDATA,EBMLM_ATFileData)
	DOCOMPL(MID_AT_FILEUID,EBMLM_ATFileUID)
}

DEF_MATR_CLASS(EBMLM_ATFileDescription,IDVALUE(MID_AT_FILEDESCRIPTION),false,EBMLDATATYPE_UTF8,"FileDescription");
DEF_MATR_CLASS(EBMLM_ATFileName,IDVALUE(MID_AT_FILENAME),false,EBMLDATATYPE_UTF8,"FileName");
DEF_MATR_CLASS(EBMLM_ATFileMimeType,IDVALUE(MID_AT_FILEMIMETYPE),false,EBMLDATATYPE_ASCII,"FileMimeType");
DEF_MATR_CLASS(EBMLM_ATFileData,IDVALUE(MID_AT_FILEDATA),false,EBMLDATATYPE_BIN,"FileData");
DEF_MATR_CLASS(EBMLM_ATFileUID,IDVALUE(MID_AT_FILEUID),false,EBMLDATATYPE_HEX,"FileUID");

DEF_MATR_CLASS(EBMLM_Chapters,IDVALUE(MID_CHAPTERS),false,true,"Chapters");
bool EBMLM_Chapters::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMPL(MID_CH_EDITIONENTRY,EBMLM_CHEditionEntry)
}

DEF_MATR_CLASS(EBMLM_CHEditionEntry,IDVALUE(MID_CH_EDITIONENTRY),true,true,"EditionEntry");
DEF_MATR_CLASS(EBMLM_CHEditionUID,IDVALUE(MID_CH_EDITIONUID),false,EBMLDATATYPE_HEX,"EditionUID");
DEF_MATR_CLASS(EBMLM_CHEditionFlagHidden,IDVALUE(MID_CH_EDITIONFLAGHIDDEN),false,EBMLDATATYPE_INT,"EditionFlagHidden");
DEF_MATR_CLASS(EBMLM_CHEditionFlagDefault,IDVALUE(MID_CH_EDITIONFLAGDEFAULT),false,EBMLDATATYPE_INT,"EditionFlagDefault");
DEF_MATR_CLASS(EBMLM_CHEditionFlagOrdered,IDVALUE(MID_CH_EDITIONFLAGORDERED),false,EBMLDATATYPE_INT,"EditionFlagOrdered");

bool EBMLM_CHEditionEntry::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CH_EDITIONUID,EBMLM_CHEditionUID)
	DOCOMP(MID_CH_EDITIONFLAGHIDDEN,EBMLM_CHEditionFlagHidden)
	DOCOMP(MID_CH_EDITIONFLAGDEFAULT,EBMLM_CHEditionFlagDefault)
	DOCOMP(MID_CH_EDITIONFLAGORDERED,EBMLM_CHEditionFlagOrdered)
	DOCOMPL(MID_CH_CHAPTERATOM,EBMLM_CHChapterAtom)
}

DEF_MATR_CLASS(EBMLM_CHChapterAtom,ETM_CH_CHAPTERATOM,true,true,"ChapterAtom");
bool EBMLM_CHChapterAtom::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CH_CHAPTERATOM,EBMLM_CHChapterAtom)
	DOCOMP(MID_CH_CHAPTERUID,EBMLM_CHChapterUID)
	DOCOMP(MID_CH_CHAPTERTIMESTART,EBMLM_CHChapterTimeStart)
	DOCOMP(MID_CH_CHAPTERTIMEEND,EBMLM_CHChapterTimeEnd)
	DOCOMP(MID_CH_CHAPTERTRACK,EBMLM_CHChapterTrack)
	DOCOMP(MID_CH_CHAPTERFLAGENABLED,EBMLM_CHChapterFlagEnabled)
	DOCOMP(MID_CH_CHAPTERFLAGHIDDEN,EBMLM_CHChapterFlagHidden)
	DOCOMP(MID_CH_CHAPPROCESS,EBMLM_CHChapProcess)
	DOCOMP(MID_CH_CHAPTERPHYSICALEQUIV,EBMLM_CHChapterPhysicalEquiv)
	DOCOMP(MID_CH_CHAPTERSEGMENTUID,EBMLM_CHChapterSegmentUID)
	DOCOMPL(MID_CH_CHAPTERDISPLAY,EBMLM_CHChapterDisplay)
}
DEF_MATR_CLASS(EBMLM_CHChapterUID,IDVALUE(MID_CH_CHAPTERUID),false,EBMLDATATYPE_HEX,"ChapterUID");
DEF_MATR_CLASS(EBMLM_CHChapterTimeStart,IDVALUE(MID_CH_CHAPTERTIMESTART),false,EBMLDATATYPE_INT,"ChapterTimeStart");
DEF_MATR_CLASS(EBMLM_CHChapterTimeEnd,IDVALUE(MID_CH_CHAPTERTIMEEND),false,EBMLDATATYPE_INT,"ChapterTimeEnd");
DEF_MATR_CLASS(EBMLM_CHChapterFlagEnabled,IDVALUE(MID_CH_CHAPTERFLAGENABLED),false,EBMLDATATYPE_INT,"ChapterFlagEnabled");
DEF_MATR_CLASS(EBMLM_CHChapterFlagHidden,IDVALUE(MID_CH_CHAPTERFLAGHIDDEN),false,EBMLDATATYPE_INT,"ChapterFlagHidden");
DEF_MATR_CLASS(EBMLM_CHChapterPhysicalEquiv,IDVALUE(MID_CH_CHAPTERPHYSICALEQUIV),false,EBMLDATATYPE_INT,"ChapterPhysicalEquiv");
DEF_MATR_CLASS(EBMLM_CHChapterSegmentUID,IDVALUE(MID_CH_CHAPTERSEGMENTUID),false,EBMLDATATYPE_HEX,"ChapterSegmentUID");

DEF_MATR_CLASS(EBMLM_CHChapterTrack,IDVALUE(MID_CH_CHAPTERTRACK),false,EBMLDATATYPE_INT,"ChapterTrack");
bool EBMLM_CHChapterTrack::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMPL(MID_CH_CHAPTERTRACKNUMBER,EBMLM_CHChapterTrackNumber)
}

DEF_MATR_CLASS(EBMLM_CHChapterDisplay,ETM_CH_CHAPTERDISPLAY,true,true,"ChapterDisplay");
bool EBMLM_CHChapterDisplay::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CH_CHAPSTRING,EBMLM_CHChapString)
	DOCOMP(MID_CH_CHAPLANGUAGE,EBMLM_CHChapLanguage)
	DOCOMPL(MID_CH_CHAPCOUNTRY,EBMLM_CHChapCountry)
}
DEF_MATR_CLASS(EBMLM_CHChapString,ETM_CH_CHAPSTRING,false,EBMLDATATYPE_UTF8,"ChapString");
DEF_MATR_CLASS(EBMLM_CHChapLanguage,ETM_CH_CHAPLANGUAGE,true,EBMLDATATYPE_ASCII,"ChapLanguage");
DEF_MATR_CLASS(EBMLM_CHChapCountry,ETM_CH_CHAPCOUNTRY,true,EBMLDATATYPE_ASCII,"ChapCountry");

DEF_MATR_CLASS(EBMLM_CHChapProcess,IDVALUE(MID_CH_CHAPPROCESS),true,true,"ChapProcess");
DEF_MATR_CLASS(EBMLM_CHChapProcessCommand,IDVALUE(MID_CH_CHAPPROCESSCOMMAND),true,true,"ChapProcessCommand");
bool EBMLM_CHChapProcess::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CH_CHAPPROCESSCODECID, EBMLM_CHChapProcessCodecID)
	DOCOMP(MID_CH_CHAPPROCESSPRIVATE, EBMLM_CHChapProcessPrivate)
	DOCOMPL(MID_CH_CHAPPROCESSCOMMAND, EBMLM_CHChapProcessCommand)
}
bool EBMLM_CHChapProcessCommand::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CH_CHAPPROCESSTIME, EBMLM_CHChapProcessTime)
	DOCOMPL(MID_CH_CHAPPROCESSDATA, EBMLM_CHChapProcessData)
}

DEF_MATR_CLASS(EBMLM_CHChapProcessCodecID,IDVALUE(MID_CH_CHAPPROCESSCODECID),false,EBMLDATATYPE_INT,"ChapProcessCodecID");
DEF_MATR_CLASS(EBMLM_CHChapProcessPrivate,IDVALUE(MID_CH_CHAPPROCESSPRIVATE),false,EBMLDATATYPE_BIN,"ChapProcessPrivate");
DEF_MATR_CLASS(EBMLM_CHChapProcessTime,IDVALUE(MID_CH_CHAPPROCESSTIME),false,EBMLDATATYPE_INT,"ChapProcessTime");
DEF_MATR_CLASS(EBMLM_CHChapProcessData,IDVALUE(MID_CH_CHAPPROCESSDATA),false,EBMLDATATYPE_HEX,"ChapProcessData");

DEF_MATR_CLASS(EBMLM_CHChapterTrackNumber,ETM_CH_CHAPTERTRACKNUMBER,false,EBMLDATATYPE_INT,"ChapterTrackNumber");

//DEF_MATR_CLASS(EBMLM_Tags,ETM_TAGS,false,true,"Tags");
DEF_MATR_CLASS(EBMLM_Void,IDVALUE(MID_VOID),true,EBMLDATATYPE_BIN,"Void");
DEF_MATR_CLASS(EBMLM_CRC32,IDVALUE(MID_CRC32),true,EBMLDATATYPE_HEX,"CRC32");
DEF_MATR_CLASS(EBMLM_Seek,IDVALUE(MID_MS_SEEK),true,true,"Seek");

bool EBMLM_Seek::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_MS_SEEKID,EBMLM_SeekID)
	DOCOMPL(MID_MS_SEEKPOSITION,EBMLM_SeekPosition)
}

DEF_MATR_CLASS(EBMLM_SeekID,IDVALUE(MID_MS_SEEKID),true,EBMLDATATYPE_HEX,"SeekID");
DEF_MATR_CLASS(EBMLM_SeekPosition,IDVALUE(MID_MS_SEEKPOSITION),true,EBMLDATATYPE_INT,"SeekPosition");
DEF_MATR_CLASS(EBMLM_CLTimeCode,IDVALUE(MID_CL_TIMECODE),false,EBMLDATATYPE_INT,"TimeCode");
DEF_MATR_CLASS(EBMLM_CLPosition,IDVALUE(MID_CL_POSITION),false,EBMLDATATYPE_INT,"Position");
DEF_MATR_CLASS(EBMLM_CLPrevSize,IDVALUE(MID_CL_PREVSIZE),false,EBMLDATATYPE_INT,"PrevSize");
DEF_MATR_CLASS(EBMLM_CLBlockGroup,IDVALUE(MID_CL_BLOCKGROUP),true,true,"BlockGroup");
//DEF_MATR_CLASS(EBMLM_CLSimpleBlock,IDVALUE(MID_CL_SIMPLEBLOCK),true,true,"SimpleBlock");
DEF_MATR_CLASS(EBMLM_CLSilentTracks,IDVALUE(MID_CL_SILENTTRACKS),true,true,"SilentTracks");
DEF_MATR_CLASS(EBMLM_CLSilentTrackNumber,IDVALUE(MID_CL_SILENTTRACKNUMBER),false,EBMLDATATYPE_INT,"SilentTrackNumber");
bool EBMLM_CLSilentTracks::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMPL(MID_CL_SILENTTRACKNUMBER,EBMLM_CLSilentTrackNumber)
}

bool EBMLM_CLBlockGroup::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CL_BLOCK,EBMLM_CLBlock)
	DOCOMP(MID_CL_BLOCKVIRTUAL,EBMLM_CLBlockVirtual)
	DOCOMP(MID_CL_BLOCKADDITIONS,EBMLM_CLBlockAdditions)
	DOCOMP(MID_CL_BLOCKDURATION,EBMLM_CLBlockDuration)
	DOCOMP(MID_CL_REFERENCEPRIORITY,EBMLM_CLReferencePriority)
	DOCOMP(MID_CL_REFERENCEBLOCK,EBMLM_CLReferenceBlock)
	DOCOMP(MID_CL_REFERENCEVIRTUAL,EBMLM_CLReferenceBlock)
	DOCOMP(MID_CL_CODECSTATE,EBMLM_CLCodecState)
	DOCOMPL(MID_CL_TIMESLICE,EBMLM_CLTimeSlice)
}


DEF_MATR_CLASS(EBMLM_CLBlockVirtual,IDVALUE(MID_CL_BLOCKVIRTUAL),true,EBMLDATATYPE_BIN,"BlockVirtual");
DEF_MATR_CLASS(EBMLM_CLBlockAdditions,IDVALUE(MID_CL_BLOCKADDITIONS),true,true,"BlockAdditions");
DEF_MATR_CLASS(EBMLM_CLBlockSamples,IDVALUE(MID_CL_BLOCKSAMPLES),false,false,"BlockSampels");

bool EBMLM_CLBlockAdditions::CheckIDs(char* iID,EBMLElement** p)
{
//	DOCOMP(MID_CL_BLOCKSAMPLES,EBMLM_CLBlockSamples)
	DOCOMPL(MID_CL_BLOCKMORE,EBMLM_CLBlockMore)
//	return true;
}

////////////////////////////////
// Matroska-Cluster-BlockMore //
////////////////////////////////

DEF_MATR_CLASS(EBMLM_CLBlockMore,IDVALUE(MID_CL_BLOCKMORE),true,true,"BlockMore");

bool EBMLM_CLBlockMore::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CL_BLOCKADDID,EBMLM_CLBlockAddID)
	DOCOMPL(MID_CL_BLOCKADDITIONAL,EBMLM_CLBlockAdditional)
}

DEF_MATR_CLASS(EBMLM_CLBlockAddID,IDVALUE(MID_CL_BLOCKADDID),false,false,"BlockAddID");
DEF_MATR_CLASS(EBMLM_CLBlockAdditional,IDVALUE(MID_CL_BLOCKADDITIONAL),false,false,"BlockAdditional");
DEF_MATR_CLASS(EBMLM_CLBlockDuration,IDVALUE(MID_CL_BLOCKDURATION),false,EBMLDATATYPE_INT,"BlockDuration");
DEF_MATR_CLASS(EBMLM_CLReferencePriority,IDVALUE(MID_CL_REFERENCEPRIORITY),false,false,"ReferencePriority");
DEF_MATR_CLASS(EBMLM_CLReferenceBlock,IDVALUE(MID_CL_REFERENCEBLOCK),true,EBMLDATATYPE_SINT,"ReferenceBlock");
DEF_MATR_CLASS(EBMLM_CLReferenceVirtual,IDVALUE(MID_CL_REFERENCEVIRTUAL),false,false,"ReferenceVirtual");
DEF_MATR_CLASS(EBMLM_CLCodecState,IDVALUE(MID_CL_CODECSTATE),false,false,"CodecState");
DEF_MATR_CLASS(EBMLM_CLTimeSlice,IDVALUE(MID_CL_TIMESLICE),true,true,"TimeSlice");

bool EBMLM_CLTimeSlice::CheckIDs(char* iID,EBMLElement** p)
{
	DOCOMP(MID_CL_LACENUMBER,EBMLM_CLTSLaceNumber)
	DOCOMP(MID_CL_FRAMENUMBER,EBMLM_CLTSFrameNumber)
	DOCOMP(MID_CL_BLOCKADDITIONID,EBMLM_CLTSBlockAdditionID)
	DOCOMP(MID_CL_DELAY,EBMLM_CLTSDelay)
	DOCOMPL(MID_CL_DURATION,EBMLM_CLTSDuration)
}

DEF_MATR_CLASS(EBMLM_CLTSLaceNumber,IDVALUE(MID_CL_LACENUMBER),false,false,"LaceNumber");
DEF_MATR_CLASS(EBMLM_CLTSFrameNumber,IDVALUE(MID_CL_FRAMENUMBER),false,false,"FrameNumber");
DEF_MATR_CLASS(EBMLM_CLTSBlockAdditionID,IDVALUE(MID_CL_BLOCKADDITIONID),false,false,"BlockAdditionalID");
DEF_MATR_CLASS(EBMLM_CLTSDelay,IDVALUE(MID_CL_DELAY),false,false,"Delay");
DEF_MATR_CLASS(EBMLM_CLTSDuration,IDVALUE(MID_CL_DURATION),false,false,"Duration");

DEF_MATR_CLASS(EBMLM_Tags,IDVALUE(MID_TAGS),true,true,"Tags");
bool EBMLM_Tags::CheckIDs(char* iID, EBMLElement** p)
{
	DOCOMPL(MID_TG_TAG,EBMLM_TGTag)
}
DEF_MATR_CLASS(EBMLM_TGTag,ETM_TG_TAG,true,true,"Tag");
bool EBMLM_TGTag::CheckIDs(char* iID, EBMLElement** p)
{
	DOCOMP(MID_TG_SIMPLETAG, EBMLM_TGSimpleTag)
	DOCOMPL(MID_TG_TARGET,EBMLM_TGTarget)
}
DEF_MATR_CLASS(EBMLM_TGTarget,ETM_TG_TARGET,false,true,"Target");
bool EBMLM_TGTarget::CheckIDs(char* iID, EBMLElement** p)
{
	DOCOMP(MID_TG_TRACKUID,EBMLM_TGTrackUID)
	DOCOMP(MID_TG_TARGETTYPEVALUE,EBMLM_TGTargetTypeValue)
	DOCOMP(MID_TG_CHAPTERUID,EBMLM_TGChapterUID)
	DOCOMP(MID_TG_ATTACHEMENTUID, EBMLM_TGAttachementUID)
	DOCOMP(MID_TG_EDITIONUID, EBMLM_TGEditionUID)
	DOCOMP(MID_TG_BITSPS,EBMLM_TGBitsPS)
	DOCOMPL(MID_TG_FRAMESPS,EBMLM_TGFramesPS)
}
DEF_MATR_CLASS(EBMLM_TGBitsPS,ETM_TG_BITSPS,false,EBMLDATATYPE_INT,"BitsPS");
DEF_MATR_CLASS(EBMLM_TGFramesPS,ETM_TG_FRAMESPS,false,EBMLDATATYPE_FLOAT,"FramesPS");
DEF_MATR_CLASS(EBMLM_TGTrackUID,ETM_TG_TRACKUID,false,EBMLDATATYPE_HEX,"TrackUID");
DEF_MATR_CLASS(EBMLM_TGTargetTypeValue,IDVALUE(MID_TG_TARGETTYPEVALUE),false,EBMLDATATYPE_INT,"TargetTypeValue");
DEF_MATR_CLASS(EBMLM_TGChapterUID,ETM_TG_CHAPTERUID,false,EBMLDATATYPE_HEX,"ChapterUID");
DEF_MATR_CLASS(EBMLM_TGEditionUID,IDVALUE(MID_TG_EDITIONUID),false,EBMLDATATYPE_HEX,"EditionUID");
DEF_MATR_CLASS(EBMLM_TGAttachementUID,IDVALUE(MID_TG_ATTACHEMENTUID),false,EBMLDATATYPE_HEX,"AttachementUID");
DEF_MATR_CLASS(EBMLM_TGTagLanguage,IDVALUE(MID_TG_TAGLANGUAGE),false,EBMLDATATYPE_UTF8,"TagLanguage");

DEF_MATR_CLASS(EBMLM_TGSimpleTag,ETM_TG_SIMPLETAG,true,EBMLDATATYPE_MASTER,"SimpleTag");
DEF_MATR_CLASS(EBMLM_TGTagName,ETM_TG_TAGNAME,false,EBMLDATATYPE_UTF8,"TagName");
DEF_MATR_CLASS(EBMLM_TGTagString,ETM_TG_TAGSTRING,false,EBMLDATATYPE_UTF8,"TagString");
DEF_MATR_CLASS(EBMLM_TGTagBinary,ETM_TG_TAGBINARY,false,EBMLDATATYPE_BIN,"TagBinary");
bool EBMLM_TGSimpleTag::CheckIDs(char* iID, EBMLElement** p)
{
	DOCOMP(MID_TG_TAGNAME,EBMLM_TGTagName)
	DOCOMP(MID_TG_TAGSTRING,EBMLM_TGTagString)
	DOCOMP(MID_TG_TAGLANGUAGE,EBMLM_TGTagLanguage)
	DOCOMPL(MID_TG_TAGBINARY,EBMLM_TGTagBinary)
}


