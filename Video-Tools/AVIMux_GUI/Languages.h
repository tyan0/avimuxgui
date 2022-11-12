#ifndef I_LANGUAGES
#define I_LANGUAGES

#include "../../Common/UTF-8.h"
#include <map>

typedef struct
{
	CUTF8	name;
//	char**	lplpStrings;
//	char**  lplpStringsUTF8;
//	wchar_t**  lplpStringsUTF16;
	std::map<DWORD, CUTF8> items;

//	DWORD*	lpdwIndices;
//	DWORD	dwEntries;
} LANGUAGE_DESCRIPTOR;

const int LOADSTRING_ANSI = 0x01;
const int LOADSTRING_UTF8 = 0x02;
const int LOADSTRING_UTF16 = 0x03;
#ifndef _UNICODE
const int LOADSTRING_TCHAR = LOADSTRING_ANSI;
#else
const int LOADSTRING_TCHAR = LOADSTRING_UTF16;
#endif


void				 SetCurrentLanguage(LANGUAGE_DESCRIPTOR* lpNewLanuage);
LANGUAGE_DESCRIPTOR* LoadLanguageFile(const char* lpcName);
char*				 LoadString(DWORD dwID, int charset = LOADSTRING_TCHAR);
void				 UnloadLanguageFile(LANGUAGE_DESCRIPTOR* lpLD);
LANGUAGE_DESCRIPTOR* GetCurrentLanguage(void);



/*
static char* languages [][2] = {
	{"English",""},
	{"German", "ger"}, 
	{"English", "eng"},
	{"Finnish", "fin"},
	{"French", "fre"},
	{"Italien", "ita"},
	{"Japanese", "jpn"},
	{"Polish", "pol"},
	{"Portuguese", "por"},

	{"Russian", "rus"},
	{"Spanish", "spa"},
	{"undefined", "und" }
};
*/
//char* languages;

// general strings

const int STR_GEN_OK			= 001;
const int STR_GEN_CANCEL		= 002;
const int STR_GEN_RESET			= 003;
const int STR_GEN_ERROR			= 106;
const int STR_GEN_WARNING		= 105;
const int STR_GEN_INFORMATION	= 104;
const int STR_SAVEAS			= 175;
const int STR_OVERWRITE         = 218;
const int STR_TOTAL_FILE_SIZE   = 219;
const int STR_CONTINUE_YESNO    = 220;

const int STR_BYTES				= 195;
const int STR_KBYTE				= 208;
const int STR_MBYTE				= 207;
const int STR_GBYTE				= 212;

// load

const int STR_LOAD_UNKNOWNOPT	= 215;
const int STR_LOAD_UNKNOWN		= 216;

// Video info list box

const int STR_VILB_STREAMSIZE_STRH	= 301;
const int STR_VILB_STREAMSIZE_INDEX	= 302;

// Listen

#define STR_FILELIST_FILENAME		401
#define STR_FILELIST_MEDIATYPE		402
#define STR_FILELIST_FORMAT			403
#define STR_FILELIST_SIZE			404
const int STR_FILELIST_REMOVE_FILES  = 405;
const int STR_FILELIST_REMOVE_STREAMS = 406;
const int STR_FILELIST_REMOVE_CONTINUE = 407;


#define STR_MEDIATYPE_VIDEO			410
#define STR_MEDIATYPE_AUDIO			411
#define STR_MEDIATYPE_SUBTITLE		412

// main window

#define STR_MAIN_S_OPENFILES		501
#define STR_MAIN_B_SAVECONFIG		502
#define STR_MAIN_B_ADDVIDEOSOURCE	504
#define	STR_MAIN_S_AVAILABLESTREAMS	505
#define STR_MAIN_S_VIDEO			506
#define STR_MAIN_S_AUDIO			507
#define STR_MAIN_S_SUBTITLES		508
#define STR_MAIN_CB_NO_AUDIO		509
#define STR_MAIN_CB_ALL_AUDIO		510
#define STR_MAIN_CB_DEFAULT_AUDIO	511
#define STR_MAIN_CB_NO_SUBTITLES	512
#define STR_MAIN_CB_ALL_SUBTITLES	513
#define STR_MAIN_S_PROTOCOL			514
#define STR_MAIN_B_OUTPUTOPTIONS	516
#define STR_MAIN_B_START			517
#define STR_MAIN_B_STOP				518
#define STR_MAIN_B_CANCEL			519
#define STR_MAIN_S_PROGRESS			520

#define	STR_MAIN_S_PRG_AMOUNTOFDATA 521
#define STR_MAIN_S_PRG_CURRFILE		522
#define STR_MAIN_S_PRG_ALLFILES		523
#define STR_MAIN_S_PRG_VIDEO		524
#define STR_MAIN_S_PRG_AUDIO		525
#define STR_MAIN_S_PRG_OVERHEAD		526
#define STR_MAIN_S_PRG_TOTAL		527
#define STR_MAIN_S_PRG_DESTFILE		528
#define STR_MAIN_S_PRG_FRAMES		529
#define STR_MAIN_S_PRG_TRANSFERRATE	530
#define STR_MAIN_S_PRG_FPS			531
#define STR_MAIN_S_PRG_PROGRESS		532
#define STR_MAIN_S_PRG_LEGIDX		533
#define STR_MAIN_S_AUDIONAME		534
#define STR_MAIN_S_AUDIODELAY		535
#define STR_MAIN_S_PRG_SUBTITLES	536
const int STR_MAIN_S_TITLE			= 537;
const int STR_MAIN_S_STRETCHBY		= 538;
const int STR_MAIN_S_RESOLUTION		= 539;
const int STR_MAIN_A_EXTRBIN        = 122;
const int STR_MAIN_A_EXTRSUB2TEXT   = 123;
const int STR_MAIN_A_EXTRACTADTS	= 124;
const int STR_MAIN_A_EXTRACTOGGV    = 119;
const int STR_MAIN_AS_DEFAULTTRACK  = 540;
const int STR_MAIN_IMMEDADDMP3      = 217;

#define STR_MAIN_M_DISPLAYPROTOCOL  213
#define STR_MAIN_M_HIDEPROTOCOL		214

// aboutbox dialog

#define STR_AB_TITLE				600

// add split point dialog

#define STR_ASP_TITLE				700
#define STR_ASP_S_NEWPART			701

// open file options dialog

#define STR_OFO_TITLE					800
#define STR_OFO_S_AVIFILES				801
#define STR_OFO_AVI_CB_MAXCHUNKSIZE		802
#define STR_OFO_AVI_CB_TRYTOREPAIR		803
#define STR_OFO_AVI_CB_FORCEMP3VBR		804
#define STR_OFO_AVI_CB_REPAIRDX50		805
#define STR_OFO_S_MP3FILES				810
#define STR_OFO_MP3_RB_CHECKCBRASK		811
#define STR_OFO_MP3_RB_CHECKCBRALWAYS	812
#define STR_OFO_MP3_RB_CHECKCBRNEVER	813
#define STR_OFO_MP3_CB_RESULTDLG		814
#define STR_OFO_S_M2F2FILES				820
#define STR_OFO_M2F2_CB_CRCCHECK		821
#define STR_OFO_S_JOINAVIS				830
#define STR_OFO_JA_CB_DONTVERIFYAC3		831
const int STR_OFO_CHAPTERS				= 832;
const int STR_OFO_CH_IMPORT				= 833;
const int STR_OFO_CH_FROMFILENAMES		= 834;
const int STR_OFO_MKV_LABEL             = 835;

const int STR_SFO_I_OVERLAPPED          = 836;

// store file options

#define STR_SFO_TITLE					900
#define STR_SFO_OPTIONS					901
const int STR_SFO_O_AVISTRUCTURE		= 902;
#define STR_SFO_OAS_CB_RECLISTS			903
#define STR_SFO_OAS_S_ODML				904
#define STR_SFO_OAS_CB_ODML				905
#define STR_SFO_OAS_S_STDIDXPERSTREAM	906
#define STR_SFO_OAS_RB_1PERRIFF			907
#define STR_SFO_OAS_RB_1PERXXXFRAMES	908
#define STR_SFO_OAS_S_FRAMES			909
#define STR_SFO_OAS_RB_AUTO				910
#define STR_SFO_OAS_CB_MAKELEGACYINDEX	911
#define STR_SFO_OAS_S_AUDIOINTERLEAVE	912
#define STR_SFO_OAS_RB_KB				913
#define STR_SFO_OAS_RB_FRAMES			914
#define STR_SFO_OAS_S_PRELOAD			915
const int STR_SFO_OAS_AC3CPF			= 916;

#define STR_SFO_OUTPUT_UNBUFFERED      921
#define STR_SFO_OUTPUT_LOGFILE         922
#define STR_SFO_OUTPUT_OVERLAPPED      923
#define STR_SFO_OUTPUT_THREADED        924

const int STR_SFO_FILENAME_LABEL        = 925;
const int STR_SFO_FILENAME_NONE         = 926;
const int STR_SFO_FILENAME_TITLE        = 927;
const int STR_SFO_FILENAME_FIRSTFILE    = 928;

#define STR_SFO_O_SPLIT					930
#define STR_SFO_OSP_CB_USEMAXSIZE		931
#define STR_SFO_OSP_B_ADVANCED			932
#define STR_SFO_OSP_CB_USENUMBERING		933
#define STR_SFO_OSP_S_FRAMES			934
#define STR_SFO_OSP_CB_USEMAXNBROFFILES	935
#define STR_SFO_OAS_CB_MP3CBRFRAMEMODE  936
const int STR_SFO_O_AVI_ADDJUNK		=   937;
const int STR_AVI1_INTERLEAVE_LABEL =   938;

const int STR_SFO_O_AVOIDSEEKOPS	=   503;
const int STR_SFO_O_MKVSTRUCTURE	=   940;
const int STR_SFO_O_MKVSTRUCTURE2	=   953;
const int STR_SFO_O_MKVSTRUCTURE_BTN=   954;
const int STR_SFO_O_MKV_LACE		=	941;
const int STR_SFO_O_MKV_CLSIZE		=   942;
const int STR_SFO_O_MKV_CLTIME		=   943;
const int STR_SFO_O_MKV_PREVSIZE    =   944;
const int STR_SFO_O_MKV_POSITION    =   945;
const int STR_SFO_O_MKV_LIMIT1STCL  =   946;
const int STR_SFO_O_MKV_DISPWH      =   947;
const int STR_SFO_O_MKV_FORCEV1		=   948;
const int STR_SFO_O_MKV_WRITECUES   =   955;
const int STR_SFO_O_MKV_CUES_OAO    =   956;
const int STR_SFO_O_MKV_2TRACKS	    =   957;
const int STR_SFO_O_MKV_INDEXCLUSTERS =   958;
const int STR_SFO_O_MKV_FLOATWIDTH  =   959;
const int STR_SFO_O_MKV_RNDELEMORDER=   960;
const int STR_SFO_O_MKV_OTHERS      =   961;
const int STR_SFO_O_MKV_HEADERSIZE  =   962;
const int STR_SFO_O_MKV_NONCLUSTERIM=   963;
const int STR_SFO_O_MKVSTRUCTURE3	=   964;
const int STR_SFO_O_MKV_CUE_INTERVAL_LABEL = 965;
const int STR_SFO_O_MKV_CUE_MINIMUM_LABEL = 966;
const int STR_SFO_O_MKV_CUE_AUTOSIZE = 967;
const int STR_SFO_O_MKV_CUE_DATARATE = 968;
const int STR_SFO_O_MKV_CUE_TARGET_RATIO = 969;
const int STR_SFO_O_MKV_HARDLINKING = 970;
const int STR_SFO_O_MKV_CUE_WRITEBLOCKNBR = 971;
const int STR_SFO_O_MKV_HEADERSTRIPPING = 972;
const int STR_SFO_O_MKV_FORCEV2		=   973;
const int STR_SFO_O_MKV_CREATE_AAAC =   974;
const int STR_MKV1_MATROSKAVERSION_GROUP = 975;


const int STR_SFO_O_GENERAL			=   950;
const int STR_SFO_O_CHAPTERS		=	951;

const int STR_SFO_OG_STDOFMT_LABEL  =   952;
const int STR_SGUI_HIGHLIGHT        =  1001;
const int STR_SGUI_LOWLIGHT         =  1002;
const int STR_SGUI_OVERWRITECONFIRMATION = 1003;
const int STR_SGUI_DONEDLG          =  1004;
const int STR_SGUI_HIGHLIGHT_DEFAULT = 1005;
const int STR_SGUI_HIGHLIGHT_NOAVI = 1006;
const int STR_SGUI_CLEARTYPE = 1007;

// set AVI header flags dialog

#define STR_SAHF_TITLE				1100
#define STR_SAHF_AVAILABLEFLAGS		1101

// set frame rate dlg

#define STR_SFR_TITLE				1200
#define STR_SFR_UNIT				1201
#define STR_SFR_FPS					1202
#define STR_SFR_MSPF				1203
#define STR_SFR_NSPF				1204

// set split points dialog

#define STR_SSP_TITLE				1300

// video information dlg

#define STR_VID_TITLE_FILE			1400
#define STR_VID_TITLE_VIDEOSOURCE	1401
#define STR_VID_APPLYCHANGES		1402

// muxing log

const int STR_MUXLOG_BEGIN				= 1500;
const int STR_MUXLOG_NEWFILE			= 1501;
const int STR_MUXLOG_DONE				= 1502;
const int STR_MUXLOG_FILESIZEREACHED	= 1503;
const int STR_MUXLOG_FILECLOSED			= 1504;
const int STR_MUXLOG_AUDIOSTREAMSIZE	= 1505;
const int STR_MUXLOG_AUDIOSTREAMS		= 1510;
const int STR_MUXLOG_SUBTITLES			= 1511;
const int STR_MUXLOG_NAME				= 1512;
const int STR_MUXLOG_DELAY				= 1513;
const int STR_MUXLOG_STREAM				= 1514;
const int STR_MUXLOG_MAXEXCEED			= 1515;
const int STR_MUXLOG_KEYFRAMEPASSED		= 1516;
const int STR_MUXLOG_MAXFILESIZE		= 1517;
const int STR_MUXLOG_ESTIMATEDOVERHEAD	= 1518;
const int STR_MUXLOG_ESTIMATEDTOTALSIZE = 1519;
const int STR_MUXLOG_DFRATBEGINNING		= 1520;
const int STR_MUXLOG_ESTIMATEDRAWSIZE	= 1521;
const int STR_MUXLOG_OVERHEADWRITTEN	= 1522;
const int STR_MUXLOG_SPLITPOINTAT		= 1523;
const int STR_MUXLOG_SPLITPOINTB0RKED	= 1524;
const int STR_MUXLOG_LACESTATS			= 1525;
const int STR_MUXLOG_CLUSTERS			= 1526;
const int STR_MUXLOG_CUES				= 1527;
const int STR_MUXLOG_OUTPUTTIMECODESCALE= 1528;
const int STR_MUXLOG_CUES_VIDEO_ON		= 1529;
const int STR_MUXLOG_CUES_VIDEO_OFF		= 1530;
const int STR_MUXLOG_CUES_AUDIO_ON		= 1531;
const int STR_MUXLOG_CUES_AUDIO_OFF		= 1532;

const int STR_MUXLOG_VIDEOLACERATE      = 1533;
const int STR_MUXLOG_VIDEOLACINGOFF     = 1534;
const int STR_MUXLOG_TRACKLACINGOFF     = 1535;
const int STR_MUXLOG_TRACKLACESIZE	    = 1536;
const int STR_MUXLOG_TRACKLACEALLOFF    = 1537;
const int STR_MUXLOG_SEEKHEAD_SIZE	    = 1538;
const int STR_MUXLOG_CLUSTERINDEX_ON	= 1539;
const int STR_MUXLOG_CLUSTERINDEX_OFF	= 1540;
const int STR_MUXLOG_LANGUAGECODE       = 1541;
const int STR_MUXLOG_UNBUFFERED_ON      = 1542;
const int STR_MUXLOG_UNBUFFERED_OFF     = 1543;
const int STR_MUXLOG_OVERLAPPED_ON      = 1544;
const int STR_MUXLOG_OVERLAPPED_OFF     = 1545;
const int STR_MUXLOG_AC3AVIPATTERN      = 1546;
const int STR_MUXLOG_DTSAVIPATTERN      = 1547;
const int STR_MUXLOG_MP3CBRDISFM        = 1548;
const int STR_MUXLOG_MP3CBRENFM         = 1549;
const int STR_MUXLOG_MP3CBRCANTDISFM    = 1550;
const int STR_MUXLOG_MP3VBRAVIPATTERN   = 1551;
const int STR_MUXLOG_FIRSTRIFFSIZE      = 1552;
const int STR_MUXLOG_1STRIFFLIST_1      = 1553;
const int STR_MUXLOG_1STRIFFLIST_2      = 1554;
const int STR_MUXLOG_AUDIOINTERLEAVE_KB = 1555;
const int STR_MUXLOG_AUDIOINTERLEAVE_FR = 1556;
const int STR_MUXLOG_RECLISTS_ON        = 1557;
const int STR_MUXLOG_RECLISTS_OFF       = 1558;
const int STR_MUXLOG_SUBTITLE_FORMAT    = 1559;
const int STR_MUXLOG_COMPRESSION_TYPE   = 1560;
const int STR_MUXLOG_LOWOVHDAVI_ON      = 1561;
const int STR_MUXLOG_LOWOVHDAVI_OFF     = 1562;
const int STR_MUXLOG_ADDINGJUNK_ON      = 1563;
const int STR_MUXLOG_ADDINGJUNK_OFF     = 1564;

const int STR_MUXLOG_CUES_SUBS_ON		= 1565;
const int STR_MUXLOG_CUES_SUBS_OFF		= 1566;
const int STR_MUXLOG_HEADERSIZE         = 1567;
const int STR_MUXLOG_CUETARGETSIZERATIO = 1568;
const int STR_MUXLOG_RANDOMIZE_ON		= 1569;
const int STR_MUXLOG_RANDOMIZE_OFF      = 1570;
const int STR_MUXLOG_CUES_WRBLOCKNBR_ON	= 1571;
const int STR_MUXLOG_CUES_WRBLOCKNBR_OFF= 1572;

const int STR_MUXLOG_FREESTYLE_ON       = 1573;
const int STR_MUXLOG_FREESTYLE_OFF      = 1574;

const int STR_MUXLOG_MATROSKAVERSION    = 1575;
const int STR_MUXLOG_FLOATWIDTH         = 1576;
const int STR_MUXLOG_OVERWRITEABLE      = 1577;
const int STR_MUXLOG_FREEDISKSPACE      = 1578;

const int STR_MUXLOG_CACHE_ON           = 1579;
const int STR_MUXLOG_CACHE_OFF          = 1580;
const int STR_MUXLOG_CACHE_INFO         = 1581;

const int STR_MUXLOG_NODISCSPACEATALL   = 1582;
const int STR_MUXLOG_NODISCSPACE        = 1583;



// subtitle listbox menu

#define STR_SUBT_EXTRACTSRT			1601
#define STR_SUBT_EXTRACTSSA			1602

// error messages

const int STR_ERR_LISTINCOMPATIBLE		= 1701;
const int STR_ERR_STREAMCOUNTDIFFERS	= 1702;
const int STR_ERR_VIDEORESOLUTIONDIFFERS= 1703;
const int STR_ERR_VIDEOCOMPRDIFFERS		= 1704;
const int STR_ERR_CODECIDDIFFERS_S		= 1707;
const int STR_ERR_AUDIOINCOMPATIBLE     = 1705;
const int STR_ERR_SUBSINCOMPATIBLE		= 1706;
const int STR_ERR_FILEINUSE				=  177;
const int STR_ERR_IMPCHAP_NONUNIQUEUID  = 1708;
const int STR_ERR_NOENDINORDEREDEDITION = 1709;
const int STR_WRN_CHAPTERSANDMAXSIZE    = 1710;
const int STR_WRN_NONUNIQUEFILENAMES    = 1711;
const int STR_ERR_OMG                   = 1712;
const int STR_ERR_SUBCOMPRESSIONINCOMPATIBLE=1713;
const int STR_ERR_OPENAVIERROR          = 1714;
const int STR_ERR_NOSEGMENTUID			= 1715;
const int STR_ERR_SAMPLERATESBAD        = 1716;
const int STR_ERR_CHANNELCOUNTBAD       = 1717;
const int STR_ERR_BADLAYERVERSIONS      = 1718;
const int STR_ERR_BADMPEGVERSIONS       = 1719;
const int STR_ERR_BADAACPROFILES        = 1720;
const int STR_ERR_COULDNOTOPENWRITE     = 1721;

//const int STR_ERR_IMPCHAP_

// hints

const int STR_HINT_VFR					= 1801;

// chapter dialog

const int STR_CHPDLG_TITLE				= 1900;
const int STR_CHPDLG_SUBCHAPTER			= 1901;
const int STR_CHPDLG_SAVEAS				= 1902;
const int STR_CHPDLG_USAGE_LABEL		= 1903;
const int STR_CHPDLG_DISP_LANGUAGE      = 1904;
const int STR_CHPDLG_DISP_TITLE         = 1905;

// RIFF Tree
const int STR_RIFFDLG_FULL		        = 1920;
const int STR_EBMLDLG_FULL				= 1920;
// popup menu

const int STR_CHPDLG_POPUP_EDITIONORDERD	= 2000;
const int STR_CHPDLG_POPUP_EDITIONHIDDEN	= 2001;
const int STR_CHPDLG_POPUP_EDITIONDEFAULT	= 2002;
const int STR_CHPDLG_POPUP_CHAPTERHIDDEN	= 2003;
const int STR_CHPDLG_POPUP_CHAPTERENABLED	= 2004;
const int STR_CHPDLG_POPUP_COPY             = 2005;
const int STR_CHPDLG_POPUP_COPYALL          = 2006;
const int STR_CHPDLG_POPUP_PASTEONSAME      = 2007;
const int STR_CHPDLG_POPUP_PASTEASSUBSCHAPS = 2008;
const int STR_CHPDLG_POPUP_PASTEALLINTOONEEDITION= 2009;
const int STR_CHPDLG_POPUP_PASTEEACHINTOONEEDITION= 2010;
const int STR_CHPDLG_POPUP_DELETECLIPBOARD  = 2011;
const int STR_CHPDLG_POPUP_REINITUIDS       = 2012;
const int STR_CHPDLG_POPUP_REINITALLUIDS    = 2013;
const int STR_CHPDLG_POPUP_COPYCHILDREN     = 2014;
const int STR_CHPDLG_POPUP_COPYALLCHILDREN  = 2015;
const int STR_CHPDLG_POPUP_NUMERATE         = 2016;




#endif