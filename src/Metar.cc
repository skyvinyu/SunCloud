#include "Metar.h"

#include <string>
#include <iostream>
#include <sstream>

extern "C" {
    int DcdMETAR( char *, Decoded_METAR * );
}

namespace altran {
namespace suncloud {

/**
 * @brief Metar::Metar Init all attribute
 */
/*Metar::Metar() :
    synoptic_cloud_type(0),
    snow_depth_group(0),
    codeName(0),
    stnid(0),
    horiz_vsby(0),
    dir_min_horiz_vsby(0),
    vsby_Dir(0),
    WxObstruct(0),
    autoIndicator(0),
    VSBY_2ndSite_LOC(0),
    SKY_2ndSite_LOC(0),
    SKY_2ndSite(0),
    SectorVsby_Dir(0),
    ObscurAloft(0),
    ObscurAloftSkyCond(0),
    VrbSkyBelow(0),
    VrbSkyAbove(0),
    LTG_DIR(0),
    CloudLow(0),
    CloudMedium(0),
    CloudHigh(0),
    CIG_2ndSite_LOC(0),
    VIRGA_DIR(0),
    TornadicType(0),
    TornadicLOC(0),
    TornadicDIR(0),
    TornadicMovDir(0),
    CHINO_LOC(0),
    VISNO_LOC(0),
    PartialObscurationAmt(0),
    PartialObscurationPhenom(0),
    SfcObscuration(0),
    charPrevailVsby(0),
    charVertVsby(0),
    TS_LOC(0),
    TS_MOVMNT(0),

    Indeterminant3_6HrPrecip(0),
    Indeterminant_24HrPrecip(0),
    CIGNO(0),
    SLPNO(0),
    ACFTMSHP(0),
    NOSPECI(0),
    FIRST(0),
    LAST(0),
    SunSensorOut(0),
    AUTO(0),
    COR(0),
    NIL_rpt(0),
    CAVOK(0),
    RVRNO(0),
    A_altstng(0),
    Q_altstng(0),
    VIRGA(0),
    VOLCASH(0),
    GR(0),
    CHINO(0),
    VISNO(0),
    PNO(0),
    PWINO(0),
    FZRANO(0),
    TSNO(0),
    DollarSign(0),
    PRESRR(0),
    PRESFR(0),
    Wshft_FROPA(0),
    OCNL_LTG(0),
    FRQ_LTG(0),
    CNS_LTG(0),
    CG_LTG(0),
    IC_LTG(0),
    CC_LTG(0),
    CA_LTG(0),
    DSNT_LTG(0),
    AP_LTG(0),
    VcyStn_LTG(0),
    OVHD_LTG(0),
    LightningVCTS(0),
    LightningTS(0),

    TornadicDistance(0),
    ob_hour(0),
    ob_minute(0),
    ob_date(0),
    minWnDir(0),
    maxWnDir(0),
    VertVsby(0),
    temp(0),
    dew_pt_temp(0),
    QFE(0),
    hectoPasc_altstng(0),
    char_prestndcy(0),
    minCeiling(0),
    maxCeiling(0),
    WshfTime_hour(0),
    WshfTime_minute(0),
    min_vrbl_wind_dir(0),
    max_vrbl_wind_dir(0),
    PKWND_dir(0),
    PKWND_speed(0),
    PKWND_hour(0),
    PKWND_minute(0),
    SKY_2ndSite_Meters(0),
    Ceiling(0),
    Estimated_Ceiling(0),
    SNINCR(0),
    SNINCR_TotalDepth(0),
    SunshineDur(0),
    ObscurAloftHgt(0),
    VrbSkyLayerHgt(0),
    Num8thsSkyObscured(0),
    CIG_2ndSite_Meters(0),
    snow_depth(0),
    BTornadicHour(0),
    BTornadicMinute(0),
    ETornadicHour(0),
    ETornadicMinute(0),

    SectorVsby(0.0),
    WaterEquivSnow(0.0),
    VSBY_2ndSite(0.0),
    prevail_vsbySM(0.0),
    prevail_vsbyM(0.0),
    prevail_vsbyKM(0.0),
    prestndcy(0.0),
    precip_amt(0.0),
    precip_24_amt(0.0),
    maxtemp(0.0),
    mintemp(0.0),
    max24temp(0.0),
    min24temp(0.0),
    minVsby(0.0),
    maxVsby(0.0),
    hourlyPrecip(0.0),
    TWR_VSBY(0.0),
    SFC_VSBY(0.0),
    Temp_2_tenths(0.0),
    DP_Temp_2_tenths(0.0),
    SLP(0.0),
    GR_Size(0.0),

    inches_altstng(0.0),

    RRVR(0),
    DVR(0),
    ReWx(0),
    winData(0),
    cldTypHgt(0)
{
}*/

Metar::Metar() {}
//Metar::~Metar() {}

void Metar::decode(const std::string& input) {
    int ret = 0;
    char *noConstInput = new char[input.length() + 1];
    strcpy(noConstInput, input.c_str());

    ret = DcdMETAR(noConstInput, this);

    delete [] noConstInput;

    if(ret != 0) {
        std::stringstream ss;
        ss << "Error to decode Metar: " << ret << "(check code error in mdsplib) - Input metar line: " << input;
        throw(std::runtime_error(ss.str()));
    }
}

/*
std::ostream& Metar::operator<<(std::ostream& os, const Metar& metar) {
    char *cStr;
    sprint_metar(cStr, &metar);
    os << cStr;
    return os;
}*/

}
}
