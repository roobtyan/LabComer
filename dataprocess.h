#ifndef DATAPROCESS_H
#define DATAPROCESS_H

#define REMOTE_NAME_1 "DT_IT_POS_MODE"
#define REMOTE_NAME_2 "ReceivedInstructionCount"
#define REMOTE_NAME_3 "ReceivedInstructionInstructionCount"
#define REMOTE_NAME_4 "FaltFlag_1"
#define REMOTE_NAME_5 "FaltFlag_2"
#define REMOTE_NAME_6 "NowLookupTableName"
#define REMOTE_NAME_7 "ControlCardInputVoltage"
#define REMOTE_NAME_8 "MainDCVoltage"
#define REMOTE_NAME_9 "MainDCCurrent"
#define REMOTE_NAME_10 "InputControlPanelVoltage"
#define REMOTE_NAME_11 "CathodeCouplingVoltage"
#define REMOTE_NAME_12 "BackupSwitchingCurrent"
#define REMOTE_NAME_13 "BackupSwitchingVoltage"
#define REMOTE_NAME_14 "InputElectricCabinetCurrent"
#define REMOTE_NAME_15 "AccelerometerOutput"
#define REMOTE_NAME_16 "Kepper2Current"
#define REMOTE_NAME_17 "Kepper1Current"
#define REMOTE_NAME_18 "CesiumCathodeVoltage"
#define REMOTE_NAME_19 "CesiumCathodeCurrent"
#define REMOTE_NAME_20 "Kepper1Voltage"
#define REMOTE_NAME_21 "Kepper2Voltage"
#define REMOTE_NAME_22 "ControlCardTemperature"
#define REMOTE_NAME_23 "ControlCardXAxisAcceleration"
#define REMOTE_NAME_24 "ControlCardYAxisAcceleration"
#define REMOTE_NAME_25 "ControlCardZAxisAcceleration"
#define REMOTE_NAME_26 "MainDCMOSTemp"
#define REMOTE_NAME_27 "MainDCTransformerTemp"
#define REMOTE_NAME_28 "FuseControlMOSTemp"
#define REMOTE_NAME_29 "BottomTempElectricCabinet"
#define REMOTE_NAME_30 "BackupDCMOSTemp"
#define REMOTE_NAME_31 "BackupDCMTransformerTemp"
#define REMOTE_NAME_32 "Kepper1DCTemp"
#define REMOTE_NAME_33 "kepper2DCTemp"
#define REMOTE_NAME_34 "CesiumPowerTemp"
#define REMOTE_NAME_35 "Cathode1IgnitionBallastTemp"
#define REMOTE_NAME_36 "Cathode2IgnitionBallastTemp"
#define REMOTE_NAME_37 "MiddleTempElectricCabinet"
#define REMOTE_NAME_38 "ConrolCardDCTemp"
#define REMOTE_NAME_39 "AdapterBoxT1Temp"
#define REMOTE_NAME_40 "AdapterBoxT2Temp"
#define REMOTE_NAME_41 "HallThrusterUnitTemp"
#define REMOTE_NAME_42 "UTCTimeSeconds"
#define REMOTE_NAME_43 "UTCTimeMilliseconds"
#define REMOTE_NAME_44 "TrackDataType"
#define REMOTE_NAME_45 "TimeSecondsCorrespondingToTrackData"
#define REMOTE_NAME_46 "TimeMillsecondsCorrespondingToTrackData"
#define REMOTE_NAME_47 "PositionCoordinateX"
#define REMOTE_NAME_48 "PositionCoordinateY"
#define REMOTE_NAME_49 "PositionCoordinateZ"
#define REMOTE_NAME_50 "SpeedX"
#define REMOTE_NAME_51 "SpeedY"
#define REMOTE_NAME_52 "SpeedZ"
#define REMOTE_NAME_53 "ManeuverState"
#define REMOTE_NAME_54 "TimeSecondsCorrespondingToAttitudeData"
#define REMOTE_NAME_55 "TimeMillsecondsCorrespondingToAttitudeData"
#define REMOTE_NAME_56 "AttitudeQuaternionQ1"
#define REMOTE_NAME_57 "AttitudeQuaternionQ2"
#define REMOTE_NAME_58 "AttitudeQuaternionQ3"
#define REMOTE_NAME_59 "AttitudeQuaternionQ4"
#define REMOTE_NAME_60 "AngularRateX"
#define REMOTE_NAME_61 "AngularRateY"
#define REMOTE_NAME_62 "AngularRateZ"
#define REMOTE_NAME_63 "Pwm24DutyCycle"
#define REMOTE_NAME_64 "Pwm22DutyCycle"
#define REMOTE_NAME_65 "Pwm16DutyCycle"
#define REMOTE_NAME_66 "Pwm12DutyCycle"
#define REMOTE_NAME_67 "ControlCardOptocouplerStatus"
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
    QString mainControlDataProcess(QString str);

    /**
     * @brief 通过长度分割
     * @param str
     * @param n
     * @return
     */
    QStringList strSplitByLength(QString str, int n);
};

#endif // DATAPROCESS_H
