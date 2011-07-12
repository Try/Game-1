#include "randomgen.h"

#include "dataCtrl/filestream.h"

const RandomGen::Type RandomGen::Max = 0xFFFFFFFF;

#include <QDebug>

enum {
    Z0 = 362436069,
    W0 = 521288629,
    ZM = 36969,
    WM = 18000
    };

RandomGen::RandomGen(){
    reset();
    }

void RandomGen::reset(){
    m_z = Z0;
    m_w = W0;
    }

RandomGen::Type RandomGen::operator ()(){
    m_z = ZM* (m_z&0xFFFF) + (m_z >> 16);
    m_w = WM* (m_w&0xFFFF) + (m_w >> 16);

    Type re =  (m_z << 16) + m_w;

    //qDebug() << re << " " << Max << " " << re;
    return re % Max;
    }

void RandomGen::serialize(FileStream &f){
    f + m_z + m_w;
    }
