#ifndef TZTABLE_H
#define TZTABLE_H

#include <stddef.h>

typedef struct davidtime{
    int hour;
    int minutes; 
}davidtime;

//offset is minutes from UTC (there are duplicates so first match wins on a linear scan)
struct tztable{
    const char *zn;
    int offset;
};

static const struct tztable tz_table[] = {
    {"ACDT", 630},  {"ACST", 570},  {"ACT", -300},  {"ACT", 480},   {"ACWST", 525},
    {"ADT", -180},  {"AEDT", 660},  {"AEST", 600},  {"AFT", 270},   {"AKDT", -480},
    {"AKST", -540}, {"ALMT", 360},  {"AMST", -180}, {"AMT", -240},  {"AMT", 240},
    {"ANAT", 720},  {"AQTT", 300},  {"ART", -180},  {"AST", 180},   {"AST", -240},
    {"AWST", 480},  {"AZOST", 0},   {"AZOT", -60},  {"AZT", 240},   {"BNT", 480},
    {"BIOT", 360},  {"BIT", -720},  {"BOT", -240},  {"BRST", -120}, {"BRT", -180},
    {"BST", 360},   {"BST", 660},   {"BST", 60},    {"BTT", 360},   {"CAT", 120},
    {"CCT", 390},   {"CDT", -300},  {"CDT", -240},  {"CEST", 120},  {"CET", 60},
    {"CHADT", 825}, {"CHAST", 765}, {"CHOT", 480},  {"CHOST", 540}, {"CHST", 600},
    {"CHUT", 600},  {"CIST", -480}, {"CKT", -600},  {"CLST", -180}, {"CLT", -240},
    {"COST", -240}, {"COT", -300},  {"CST", -360},  {"CST", 480},   {"CST", -300},
    {"CVT", -60},   {"CWST", 525},  {"CXT", 420},   {"DAVT", 420},  {"DDUT", 600},
    {"DFT", 60},    {"EASST", -300},{"EAST", -360}, {"EAT", 180},   {"ECT", -240},
    {"ECT", -300},  {"EDT", -240},  {"EEST", 180},  {"EET", 120},   {"EGST", 0},
    {"EGT", -60},   {"EST", -300},  {"FET", 180},   {"FJT", 720},   {"FKST", -180},
    {"FKT", -240},  {"FNT", -120},  {"GALT", -360}, {"GAMT", -540}, {"GET", 240},
    {"GFT", -180},  {"GILT", 720},  {"GIT", -540},  {"GMT", 0},     {"GST", -120},
    {"GST", 240},   {"GYT", -240},  {"HDT", -540},  {"HAEC", 120},  {"HST", -600},
    {"HKT", 480},   {"HMT", 300},   {"HOVST", 480}, {"HOVT", 420},  {"ICT", 420},
    {"IDLW", -720}, {"IDT", 180},   {"IOT", 360},   {"IRDT", 270},  {"IRKT", 480},
    {"IRST", 210},  {"IST", 330},   {"IST", 60},    {"IST", 120},   {"JST", 540},
    {"KALT", 120},  {"KGT", 360},   {"KOST", 660},  {"KRAT", 420},  {"KST", 540},
    {"LHST", 630},  {"LHST", 660},  {"LINT", 840},  {"MAGT", 720},  {"MART", -570},
    {"MAWT", 300},  {"MDT", -360},  {"MET", 60},    {"MEST", 120},  {"MHT", 720},
    {"MIST", 660},  {"MIT", -570},  {"MMT", 390},   {"MSK", 180},   {"MST", 480},
    {"MST", -420},  {"MUT", 240},   {"MVT", 300},   {"MYT", 480},   {"NCT", 660},
    {"NDT", -150},  {"NFT", 660},   {"NOVT", 420},  {"NPT", 345},   {"NST", -210},
    {"NT", -210},   {"NUT", -660},  {"NZDT", 780},  {"NZDST", 780}, {"NZST", 720},
    {"OMST", 360},  {"ORAT", 300},  {"PDT", -420},  {"PET", -300},  {"PETT", 720},
    {"PGT", 600},   {"PHOT", 780},  {"PHT", 480},   {"PHST", 480},  {"PKT", 300},
    {"PMDT", -120}, {"PMST", -180}, {"PONT", 660},  {"PST", -480},  {"PWT", 540},
    {"PYST", -180}, {"PYT", -240},  {"RET", 240},   {"ROTT", -180}, {"SAKT", 660},
    {"SAMT", 240},  {"SAST", 120},  {"SBT", 660},   {"SCT", 240},   {"SDT", -600},
    {"SGT", 480},   {"SLST", 330},  {"SRET", 660},  {"SRT", -180},  {"SST", -660},
    {"SYOT", 180},  {"TAHT", -600}, {"THA", 420},   {"TFT", 300},   {"TJT", 300},
    {"TKT", 780},   {"TLT", 540},   {"TMT", 300},   {"TRT", 180},   {"TOT", 780},
    {"TST", 480},   {"TVT", 720},   {"ULAST", 540}, {"ULAT", 480},  {"UTC", 0},
    {"UYST", -120}, {"UYT", -180},  {"UZT", 300},   {"VET", -240},  {"VLAT", 600},
    {"VOLT", 180},  {"VOST", 360},  {"VUT", 660},   {"WAKT", 720},  {"WAST", 120},
    {"WAT", 60},    {"WEST", 60},   {"WET", 0},     {"WIB", 420},   {"WIT", 540},
    {"WITA", 480},  {"WGST", -120}, {"WGT", -180},  {"WST", 480},   {"YAKT", 540},
    {"YEKT", 300},
};

#define TZTABLE_LENGHT (sizeof(tz_table) / sizeof(tz_table[0]))

#endif
