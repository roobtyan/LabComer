#include "dataprocess.h"
#include "QDebug"

DataProcess::DataProcess()
{
    remoteNameList.append(REMOTE_NAME_1);
    remoteNameList.append(REMOTE_NAME_2);
    remoteNameList.append(REMOTE_NAME_3);
    remoteNameList.append(REMOTE_NAME_4);
    remoteNameList.append(REMOTE_NAME_5);
    remoteNameList.append(REMOTE_NAME_6);
    remoteNameList.append(REMOTE_NAME_7);
    remoteNameList.append(REMOTE_NAME_8);
    remoteNameList.append(REMOTE_NAME_9);
    remoteNameList.append(REMOTE_NAME_10);
    remoteNameList.append(REMOTE_NAME_11);
    remoteNameList.append(REMOTE_NAME_12);
    remoteNameList.append(REMOTE_NAME_13);
    remoteNameList.append(REMOTE_NAME_14);
    remoteNameList.append(REMOTE_NAME_15);
    remoteNameList.append(REMOTE_NAME_16);
    remoteNameList.append(REMOTE_NAME_17);
    remoteNameList.append(REMOTE_NAME_18);
    remoteNameList.append(REMOTE_NAME_19);
    remoteNameList.append(REMOTE_NAME_20);
    remoteNameList.append(REMOTE_NAME_21);
    remoteNameList.append(REMOTE_NAME_22);
    remoteNameList.append(REMOTE_NAME_23);
    remoteNameList.append(REMOTE_NAME_24);
    remoteNameList.append(REMOTE_NAME_25);
    remoteNameList.append(REMOTE_NAME_26);
    remoteNameList.append(REMOTE_NAME_27);
    remoteNameList.append(REMOTE_NAME_28);
    remoteNameList.append(REMOTE_NAME_29);
    remoteNameList.append(REMOTE_NAME_30);
    remoteNameList.append(REMOTE_NAME_31);
    remoteNameList.append(REMOTE_NAME_32);
    remoteNameList.append(REMOTE_NAME_33);
    remoteNameList.append(REMOTE_NAME_34);
    remoteNameList.append(REMOTE_NAME_35);
    remoteNameList.append(REMOTE_NAME_36);
    remoteNameList.append(REMOTE_NAME_37);
    remoteNameList.append(REMOTE_NAME_38);
    remoteNameList.append(REMOTE_NAME_39);
    remoteNameList.append(REMOTE_NAME_40);
    remoteNameList.append(REMOTE_NAME_41);
    remoteNameList.append(REMOTE_NAME_42);
    remoteNameList.append(REMOTE_NAME_43);
    remoteNameList.append(REMOTE_NAME_44);
    remoteNameList.append(REMOTE_NAME_45);
    remoteNameList.append(REMOTE_NAME_46);
    remoteNameList.append(REMOTE_NAME_47);
    remoteNameList.append(REMOTE_NAME_48);
    remoteNameList.append(REMOTE_NAME_49);
    remoteNameList.append(REMOTE_NAME_50);
    remoteNameList.append(REMOTE_NAME_51);
    remoteNameList.append(REMOTE_NAME_52);
    remoteNameList.append(REMOTE_NAME_53);
    remoteNameList.append(REMOTE_NAME_54);
    remoteNameList.append(REMOTE_NAME_55);
    remoteNameList.append(REMOTE_NAME_56);
    remoteNameList.append(REMOTE_NAME_57);
    remoteNameList.append(REMOTE_NAME_58);
    remoteNameList.append(REMOTE_NAME_59);
    remoteNameList.append(REMOTE_NAME_60);
    remoteNameList.append(REMOTE_NAME_61);
    remoteNameList.append(REMOTE_NAME_62);
    remoteNameList.append(REMOTE_NAME_63);
    remoteNameList.append(REMOTE_NAME_64);
    remoteNameList.append(REMOTE_NAME_65);
    remoteNameList.append(REMOTE_NAME_66);
    remoteNameList.append(REMOTE_NAME_67);
    remoteNameList.append(REMOTE_NAME_68);
    remoteNameList.append(REMOTE_NAME_69);
    remoteNameList.append(REMOTE_NAME_70);
    remoteNameList.append(REMOTE_NAME_71);
    remoteNameList.append(REMOTE_NAME_72);
    remoteNameList.append(REMOTE_NAME_73);
    remoteNameList.append(REMOTE_NAME_74);
    remoteNameList.append(REMOTE_NAME_75);
    remoteNameList.append(REMOTE_NAME_76);
    remoteNameList.append(REMOTE_NAME_77);
    remoteNameList.append(REMOTE_NAME_78);
    remoteNameList.append(REMOTE_NAME_79);
    remoteNameList.append(REMOTE_NAME_80);
    remoteNameList.append(REMOTE_NAME_81);
    remoteNameList.append(REMOTE_NAME_82);
    remoteNameList.append(REMOTE_NAME_83);
    remoteNameList.append(REMOTE_NAME_84);
    remoteNameList.append(REMOTE_NAME_85);
    remoteNameList.append(REMOTE_NAME_86);
    remoteNameList.append(REMOTE_NAME_87);
    remoteNameList.append(REMOTE_NAME_88);
    remoteNameList.append(REMOTE_NAME_89);
    remoteNameList.append(REMOTE_NAME_90);
    remoteNameList.append(REMOTE_NAME_91);
    remoteNameList.append(REMOTE_NAME_92);
    remoteNameList.append(REMOTE_NAME_93);
    remoteNameList.append(REMOTE_NAME_94);
    remoteNameList.append(REMOTE_NAME_95);
    remoteNameList.append(REMOTE_NAME_96);
    remoteNameList.append(REMOTE_NAME_97);
    remoteNameList.append(REMOTE_NAME_98);
    remoteNameList.append(REMOTE_NAME_99);
    remoteNameList.append(REMOTE_NAME_100);
    remoteNameList.append(REMOTE_NAME_101);
    remoteNameList.append(REMOTE_NAME_102);
    remoteNameList.append(REMOTE_NAME_103);
    remoteNameList.append(REMOTE_NAME_104);
    remoteNameList.append(REMOTE_NAME_105);
}

QString DataProcess::mainControlDataProcess(QString str)
{
    // 数据处理流程
    // 1. 去掉帧头、帧尾
    // 2. 用8个字符为1组（4B），转为uint
    // 3. 按照表格分类，将数据按需求转换
    QString result;
    QString resultTemp = str;
    // 先去掉帧头帧尾
    resultTemp = resultTemp.mid(8, resultTemp.size()-16);
    // 8个字符分为1组
    QStringList strList = strSplitByLength(resultTemp, 8);
    // 通过遍历，计算数值，返回结果
    for(int i = 1; i <= strList.size(); i++) {
        // 得到定义的值
        result.append("[" + remoteNameList[i] + "]");
        //  无符号整型：1~6、22、42~46、53~55、63~67、103~105
        //  单精度浮点：7~21、23~41、47~52、56~62、68~102
        if ((i >= 1 && i <= 6) || i == 22 || (i >= 42 && i <= 46) ||
                (i >=53 && i <=55) || (i >= 63 && i <= 67) || (i >= 103 && i <= 105)) {
            long double res = hexToDec(strList[i-1]);
            QString decStr = QString::number(res, '.', 0);
            result.append("[" + decStr + "]");
        } else if ((i >= 7 && i <= 21) || (i >= 23 && i <= 41) ||
                   (i >= 47 && i <= 52) || (i >= 56 && i<= 62) || (i >= 68 && i <= 102)) {
            QString floatStr = hexToFloat(strList[i-1]);
            result.append("[" + floatStr + "]");
        }
        result.append("[" + strList[i-1] + "]\n");
    }
    return result;
}

QStringList DataProcess::strSplitByLength(QString str, int n)
{
    // 使用循环构造List
    QStringList resultList;
    int pos = 0; // 定位截取位置
    for (int i = 0; i < str.size() / n; i++) {
        QString strTmp = str.mid(pos, n);
        resultList.append(strTmp);
        pos += n;  // 用POS来定位
    }
    return resultList;
}
