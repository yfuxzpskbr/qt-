#include "dataconfig.h"
#include <QMap>
#include <QVector>
#include <QDebug>

//0表示空地
//1表示墙
//2表示人
//3表示箱子
//4表示目的地
//6表示人在目的地
//7表示箱子在目的地


dataconfig::dataconfig(QObject *parent) : QObject(parent)
{
    QVector <QVector <int >> v;
    //第一关地图
    int tempmap1[7][7] = {
        {1,1,1,1,1,1,0},
        {1,2,0,0,0,1,0},
        {1,0,0,0,3,1,0},
        {1,0,0,0,0,1,0},
        {1,0,0,0,4,1,0},
        {1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap1[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(1,v);
    this->row.insert(1,6);
    this->col.insert(1,6);
    v.clear();

    //第二关的地图
    int tempmap2[7][7] = {
        {1,1,1,1,1,1,0},
        {1,2,0,0,0,1,0},
        {1,0,0,0,0,1,0},
        {1,0,0,3,4,1,0},
        {1,0,4,3,0,1,0},
        {1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap2[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(2,v);
    this->row.insert(2,6);
    this->col.insert(2,6);
    v.clear();

    //第三关的地图
    int tempmap3[7][7]={
        {1,1,1,1,1,1,0},
        {1,0,0,2,0,1,0},
        {1,0,3,3,0,1,1},
        {1,0,1,4,0,4,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap3[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(3,v);
    this->row.insert(3,6);
    this->col.insert(3,7);
    v.clear();

    //第四关
    int tempmap4[7][7] ={
        {1,1,1,1,1,1,0},
        {1,2,0,0,0,1,0},
        {1,4,3,7,0,1,0},
        {1,0,0,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap4[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(4,v);
    this->row.insert(4,6);
    this->col.insert(4,6);
    v.clear();

    //第五关
    int tempmap5[7][7] ={
        {0,0,1,1,1,1,0},
        {0,0,1,0,0,1,0},
        {1,1,1,4,3,1,1},
        {1,0,2,3,0,0,1},
        {1,0,0,4,0,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap5[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(5,v);
    this->row.insert(5,7);
    this->col.insert(5,7);
    v.clear();

    //第六关

    int tempmap6[7][7] ={
        {0,0,1,1,1,1,0},
        {0,0,1,0,0,1,0},
        {1,1,1,0,3,1,1},
        {1,4,2,0,0,0,1},
        {1,0,0,7,0,0,1},
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0}

    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap6[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(6,v);
    this->row.insert(6,6);
    this->col.insert(6,7);
    v.clear();
    //第七关

    int tempmap7[7][7] ={
        {1,1,1,1,1,0,0},
        {1,4,4,2,1,0,0},
        {1,0,0,3,1,1,0},
        {1,0,3,0,0,1,0},
        {1,1,0,0,0,1,0},
        {0,1,1,1,1,1,0},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap7[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(7,v);
    this->row.insert(7,6);
    this->col.insert(7,6);
    v.clear();
    //第八关

    int tempmap8[7][7] ={
        {0,1,1,1,1,1,1},
        {0,1,0,0,4,4,1},
        {1,1,3,0,1,2,1},
        {1,0,0,0,3,0,1},
        {1,0,0,0,1,0,1},
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0}

    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap8[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(8,v);
    this->row.insert(8,6);
    this->col.insert(8,7);
    v.clear();
    //第九关

    int tempmap9[7][7] ={
        {1,1,1,1,1,1,1},
        {1,2,0,0,1,4,1},
        {1,0,0,3,3,0,1},
        {1,0,0,0,0,4,1},
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap9[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(9,v);
    this->row.insert(9,5);
    this->col.insert(9,7);
    v.clear();
    //第十关
    int tempmap10[7][7] ={
        {0,1,1,1,1,1,0},
        {0,1,0,0,0,1,0},
        {1,1,1,0,0,1,1},
        {1,2,0,7,3,0,1},
        {1,0,1,4,1,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap10[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(10,v);
    this->row.insert(10,7);
    this->col.insert(10,7);
    v.clear();

    //第十一关
    int tempmap11[7][7] ={
        {0,0,1,1,1,1,0},
        {0,0,1,0,0,1,0},
        {1,1,1,0,0,1,0},
        {1,2,0,3,3,1,1},
        {1,0,4,0,4,0,1},
        {1,1,1,0,0,0,1},
        {0,0,1,1,1,1,1}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap11[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(11,v);
    this->row.insert(11,7);
    this->col.insert(11,7);
    v.clear();

    //第十二关
    int tempmap12[7][7] ={
        {0,0,1,1,1,1,0},
        {1,1,1,0,0,1,0},
        {1,0,0,0,0,1,1},
        {1,2,3,3,0,0,1},
        {1,4,0,1,0,0,1},
        {1,4,0,1,0,0,1},
        {1,1,1,1,1,1,1}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap12[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(12,v);
    this->row.insert(12,7);
    this->col.insert(12,7);
    v.clear();

    //第十三关
    int tempmap13[7][7] ={
        {0,1,1,1,1,0,0},
        {0,1,0,0,1,0,0},
        {1,1,4,0,1,1,1},
        {1,0,3,3,0,0,1},
        {1,0,0,0,0,6,1},
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap13[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(13,v);
    this->row.insert(13,6);
    this->col.insert(13,7);
    v.clear();

    //第十四关
    int tempmap14[7][7] ={
        {1,1,1,1,1,1,0},
        {1,6,4,4,0,1,0},
        {1,3,1,3,0,1,0},
        {1,0,3,0,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap14[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(14,v);
    this->row.insert(14,6);
    this->col.insert(14,6);
    v.clear();

    //第十五关
    int tempmap15[7][7] ={
        {1,1,1,1,1,1,1},
        {1,0,0,4,4,4,1},
        {1,0,3,3,3,0,1},
        {1,0,0,1,2,0,1},
        {1,0,0,1,0,0,1},
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap15[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(15,v);
    this->row.insert(15,6);
    this->col.insert(15,7);
    v.clear();

    //第十六关
    int tempmap16[7][7] ={
        {1,1,1,1,1,1,0},
        {1,4,0,0,4,1,0},
        {1,0,0,0,0,1,0},
        {1,3,1,3,3,1,0},
        {1,2,0,0,4,1,0},
        {1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap16[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(16,v);
    this->row.insert(16,6);
    this->col.insert(16,6);
    v.clear();



    //第十七关
    int tempmap17[7][7] ={
        {1,1,1,1,1,1,1},
        {1,0,0,6,0,0,1},
        {1,0,3,7,3,0,1},
        {1,0,1,4,1,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap17[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(17,v);
    this->row.insert(17,6);
    this->col.insert(17,7);
    v.clear();

    //第十八关
    int tempmap18[7][7] ={
        {1,1,1,1,1,1,0},
        {1,4,3,2,0,1,0},
        {1,4,3,3,0,1,0},
        {1,4,1,0,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap18[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(18,v);
    this->row.insert(18,6);
    this->col.insert(18,6);
    v.clear();

    //第十九关
    int tempmap19[7][7] ={
        {1,1,1,1,1,1,1},
        {1,0,0,0,4,0,1},
        {1,0,1,0,1,0,1},
        {1,0,3,3,3,0,1},
        {1,0,1,2,1,4,1},
        {1,0,0,4,0,0,1},
        {1,1,1,1,1,1,1}
    };
    for(int i=0;i<7;i++){
        QVector <int> v1;
        for(int j=0;j<7;j++){
            v1.push_back(tempmap19[i][j]);
        }
        v.push_back(v1);
    }
    this->mapdata.insert(19,v);
    this->row.insert(19,7);
    this->col.insert(19,7);
    v.clear();

    //第二十关
    int tempmap20[7][7] ={
        {1,1,1,1,1,1,1},
        {1,4,0,4,0,4,1},
        {1,0,0,0,0,0,1},
        {1,1,3,3,3,1,1},
        {1,0,2,1,0,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1}
       };
       for(int i=0;i<7;i++){
           QVector <int> v1;
           for(int j=0;j<7;j++){
               v1.push_back(tempmap20[i][j]);
           }
           v.push_back(v1);
       }
       this->mapdata.insert(20,v);
       this->row.insert(20,7);
       this->col.insert(20,7);
       v.clear();

       //第二十一关
       int tempmap21[7][7] ={
           {1,1,1,1,1,0,0},
           {1,0,0,0,1,0,0},
           {1,0,0,0,1,0,0},
           {1,4,3,4,1,0,0},
           {1,3,6,3,1,0,0},
           {1,0,0,0,1,0,0},
           {1,1,1,1,1,0,0}
          };
          for(int i=0;i<7;i++){
              QVector <int> v1;
              for(int j=0;j<7;j++){
                  v1.push_back(tempmap21[i][j]);
              }
              v.push_back(v1);
          }
          this->mapdata.insert(21,v);
          this->row.insert(21,7);
          this->col.insert(21,5);
          v.clear();

          //第二十二关
          int tempmap22[7][7] ={
              {0,1,1,1,1,1,0},
              {1,1,0,0,4,1,0},
              {1,4,3,0,4,1,0},
              {1,3,0,3,2,1,0},
              {1,0,0,0,1,1,0},
              {1,1,1,1,1,0,0},
              {0,0,0,0,0,0,0}
             };
             for(int i=0;i<7;i++){
                 QVector <int> v1;
                 for(int j=0;j<7;j++){
                     v1.push_back(tempmap22[i][j]);
                 }
                 v.push_back(v1);
             }
             this->mapdata.insert(22,v);
             this->row.insert(22,6);
             this->col.insert(22,6);
             v.clear();

             //第二十三关

             int tempmap23[7][7] ={
                 {1,1,1,1,1,0,0},
                 {1,4,0,4,1,0,0},
                 {1,1,0,0,1,0,0},
                 {1,0,3,0,1,0,0},
                 {1,0,3,3,1,0,0},
                 {1,4,1,2,1,0,0},
                 {1,1,1,1,1,0,0}
                };
                for(int i=0;i<7;i++){
                    QVector <int> v1;
                    for(int j=0;j<7;j++){
                        v1.push_back(tempmap23[i][j]);
                    }
                    v.push_back(v1);
                }
                this->mapdata.insert(23,v);
                this->row.insert(23,7);
                this->col.insert(23,5);
                v.clear();

                //二十四关
                int tempmap24[7][7] ={
                    {1,1,1,1,1,1,1},
                    {1,0,0,2,0,4,1},
                    {1,0,0,1,0,4,1},
                    {1,0,3,3,3,4,1},
                    {1,0,0,1,0,0,1},
                    {1,1,1,1,1,1,1},
                    {0,0,0,0,0,0,0}
                   };
                   for(int i=0;i<7;i++){
                       QVector <int> v1;
                       for(int j=0;j<7;j++){
                           v1.push_back(tempmap24[i][j]);
                       }
                       v.push_back(v1);
                   }
                   this->mapdata.insert(24,v);
                   this->row.insert(24,6);
                   this->col.insert(24,7);
                   v.clear();

                   //第二十五关
                   int tempmap25[7][7] ={
                       {1,1,1,1,1,0,0},
                       {1,0,0,0,1,1,0},
                       {1,0,3,6,4,1,0},
                       {1,0,3,3,0,1,0},
                       {1,0,0,1,4,1,0},
                       {1,1,1,1,1,1,0},
                       {0,0,0,0,0,0,0}
                      };
                      for(int i=0;i<7;i++){
                          QVector <int> v1;
                          for(int j=0;j<7;j++){
                              v1.push_back(tempmap25[i][j]);
                          }
                          v.push_back(v1);
                      }
                      this->mapdata.insert(25,v);
                      this->row.insert(25,6);
                      this->col.insert(25,6);
                      v.clear();
      //模板
//          int tempmap/*关卡数*/[7][7] ={

//          };
//          for(int i=0;i<7;i++){
//              QVector <int> v1;
//              for(int j=0;j<7;j++){
//                  v1.push_back(tempmap/*关卡数*/[i][j]);
//              }
//              v.push_back(v1);
//          }
//          this->mapdata.insert(/*关卡数*/,v);
//          this->row.insert(/*关卡数*/,/*该关卡行数*/);
//          this->col.insert(/*关卡数*/,/*该关卡列数*/);
//          v.clear();
}
