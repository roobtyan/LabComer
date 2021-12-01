#ifndef DATAPROCESS_H
#define DATAPROCESS_H

#define REMOTE_NAME_1 "0x12+command type+process+mode"
#define REMOTE_NAME_2 "Received command counter"
#define REMOTE_NAME_3 "Received control command counter"
#define REMOTE_NAME_4 "Error flag1"
#define REMOTE_NAME_5 "Error flag2"
#define REMOTE_NAME_6 "Lookup table number"
#define REMOTE_NAME_7 "Input voltage(control card)"
#define REMOTE_NAME_8 "Primary main DCDC voltage"
#define REMOTE_NAME_9 "Primary main DCDC current"
#define REMOTE_NAME_10 "Input voltage"
#define REMOTE_NAME_11 "CathodeCouplingVoltage"
#define REMOTE_NAME_12 "Secondary main DCDC current"
#define REMOTE_NAME_13 "Secondary main DCDC voltage"
#define REMOTE_NAME_14 "Input current"
#define REMOTE_NAME_15 "Accelerometer output"
#define REMOTE_NAME_16 "Keeper2 current"
#define REMOTE_NAME_17 "Keeper1 current"
#define REMOTE_NAME_18 "Cs voltage"
#define REMOTE_NAME_19 "Cs current"
#define REMOTE_NAME_20 "Keeper1 voltage"
#define REMOTE_NAME_21 "Keeper2 voltage"
#define REMOTE_NAME_22 "Temp--MCU"
#define REMOTE_NAME_23 "Accelerometer X"
#define REMOTE_NAME_24 "Accelerometer Y"
#define REMOTE_NAME_25 "Accelerometer Z"
#define REMOTE_NAME_26 "Temp--PrimaryMainMOS"
#define REMOTE_NAME_27 "Temp--PrimaryTransformer"
#define REMOTE_NAME_28 "Temp--FuseMOS"
#define REMOTE_NAME_29 "Temp--BoxBottomWall"
#define REMOTE_NAME_30 "Temp--SecondaryMainMOS"
#define REMOTE_NAME_31 "Temp--SecondaryTransformer"
#define REMOTE_NAME_32 "Temp--Keeper1DCDC"
#define REMOTE_NAME_33 "Temp--Keeper2DCDC"
#define REMOTE_NAME_34 "Temp--CsDCDC"
#define REMOTE_NAME_35 "Temp--Ballast1"
#define REMOTE_NAME_36 "Temp--Ballast2"
#define REMOTE_NAME_37 "Temp--BoxMiddleWall"
#define REMOTE_NAME_38 "Temp--Control card"
#define REMOTE_NAME_39 "Temp--JunctionBox1"
#define REMOTE_NAME_40 "Temp--JunctionBox2"
#define REMOTE_NAME_41 "Temp--HETunit"
#define REMOTE_NAME_42 "Broadcast--UTC sec"
#define REMOTE_NAME_43 "Brst--UTC ms"
#define REMOTE_NAME_44 "Brst--Orbit type"
#define REMOTE_NAME_45 "Brst--Orbit sec"
#define REMOTE_NAME_46 "Brst--Orbit ms"
#define REMOTE_NAME_47 "Brst--LOC_X"
#define REMOTE_NAME_48 "Brst--LOC_Y"
#define REMOTE_NAME_49 "Brst--LOC_Z"
#define REMOTE_NAME_50 "Brst--VOC_X"
#define REMOTE_NAME_51 "Brst--VOC_Y"
#define REMOTE_NAME_52 "Brst--VOC_Z"
#define REMOTE_NAME_53 "Brst--POSE_TYPE"
#define REMOTE_NAME_54 "Brst--POSE_sec"
#define REMOTE_NAME_55 "Brst--POSE_ms"
#define REMOTE_NAME_56 "Brst--POSE_Q1"
#define REMOTE_NAME_57 "Brst--POSE Q2"
#define REMOTE_NAME_58 "Brst--POSE Q3"
#define REMOTE_NAME_59 "Brst--POSE Q4"
#define REMOTE_NAME_60 "Brst--OMEGA X"
#define REMOTE_NAME_61 "Brst--OMEGA Y"
#define REMOTE_NAME_62 "Broadcast--OMEGA Z"
#define REMOTE_NAME_63 "PWM24(Snd Volt) duty set"
#define REMOTE_NAME_64 "PWM22(Snd curt) duty set"
#define REMOTE_NAME_65 "PWM16(Prim Volt) duty set"
#define REMOTE_NAME_66 "PWM12(Prim curt) dyty set"
#define REMOTE_NAME_67 "Optocoupler state"
#define REMOTE_NAME_68 "adc_InputVoltage"
#define REMOTE_NAME_69 "adc_ValveVoltage"
#define REMOTE_NAME_70 "adc_HeaterVoltage"
#define REMOTE_NAME_71 "adc_InputCurrent"
#define REMOTE_NAME_72 "adc_ValveCurrent"
#define REMOTE_NAME_73 "adc_HeaterCurrent"
#define REMOTE_NAME_74 "adc_RTD_1"
#define REMOTE_NAME_75 "adc_RTD_2"
#define REMOTE_NAME_76 "adc_RTD_3"
#define REMOTE_NAME_77 "adc_RTD_4"
#define REMOTE_NAME_78 "adc_TempControlCard"
#define REMOTE_NAME_79 "adc_PressureTank"
#define REMOTE_NAME_80 "adc_PressureAfterPR"
#define REMOTE_NAME_81 "adc_PressureHET"
#define REMOTE_NAME_82 "adc_PressureM_1"
#define REMOTE_NAME_83 "adc_PressureM_2"
#define REMOTE_NAME_84 "PIDOut"
#define REMOTE_NAME_85 "U_InputCurrent"
#define REMOTE_NAME_86 "U_InputVotage"
#define REMOTE_NAME_87 "U_ValveCurrent"
#define REMOTE_NAME_88 "U_ValveVoltage"
#define REMOTE_NAME_89 "U_Emco_InputCurrent"
#define REMOTE_NAME_90 "U_Emco_InputVoltage"
#define REMOTE_NAME_91 "U_Emco_OutputVoltage"
#define REMOTE_NAME_92 "U_Emco_OutputCurrent"
#define REMOTE_NAME_93 "U_InputPressure"
#define REMOTE_NAME_94 "U_MidPressure"
#define REMOTE_NAME_95 "U_LowPressure"
#define REMOTE_NAME_96 "U_RTD_1"
#define REMOTE_NAME_97 "U_RTD_2"
#define REMOTE_NAME_98 "U_RTD_3"
#define REMOTE_NAME_99 "U_RTD_4"
#define REMOTE_NAME_100 "U_TempControlCard"
#define REMOTE_NAME_101 "U_PIDOut"
#define REMOTE_NAME_102 "BackupFloatData1"
#define REMOTE_NAME_103 "ChangedP1"
#define REMOTE_NAME_104 "BackupUInt1"
#define REMOTE_NAME_105 "BackupUInt2"

#include <QString>
#include <QStringList>
#include "QHelper.h"
#include "remotecommand.h"


class DataProcess
{
public:
    QStringList remoteNameList;

    DataProcess();

    /**
     * @brief 主控数据处理
     * @param str
     * @return
     */
    QList<RemoteCommand> mainControlDataProcess(QString str);

    /**
     * @brief 通过长度分割
     * @param str
     * @param n
     * @return
     */
    QStringList strSplitByLength(QString str, int n);
};

#endif // DATAPROCESS_H
