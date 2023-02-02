//////////////////////////////////////////////////
// 2560 跟随互动程序
//算法设计完成
/////////////////////////////////////////////////


//输入
//3种传感器接口
const int IN1=2;//振动传感器
const int IN2=3;//土壤湿度传感器
const int IN3=4;//雨滴传感器





//L298  -- 1#

///振动传感器4电机
//电机1
const int MT1_IN1=8;//
const int MT1_IN2=9;//
//电机2
const int MT2_IN3=10;//
const int MT2_IN4=11;//

//L298  -- 2#
//电机3
const int MT3_IN1=12;//
const int MT3_IN2=13;//
//电机4
const int MT4_IN3=53;//
const int MT4_IN4=51;//
/////////////////////////////////








//土壤传感器电机2个
//L298  -- 3#
//电机5
const int MT5_IN1=49;//
const int MT5_IN2=47;//
//电机6
const int MT6_IN3=45;//
const int MT6_IN4=43;//



//水滴传感器电机 1个
//L298  -- 4#
const int MT7_IN1=39;//
const int MT7_IN2=37;//



//SENSOR1 TIME
#define TIMEA 500  //1#动作序列正反时间

#define TIMEB 200  //2#动作序列正反时间
#define LOOPX 3 //循环执行次数


#define DELAY2 300   //土壤湿度延时

#define DELAY3 300   //雨滴延时









//数据缓存
//1
unsigned char lifeA1=0;
int cntA1=0;

unsigned char lifeA2=0;
int cntA2=0;

unsigned char his1=1;
unsigned char cur1=1;

unsigned char XUNHUANX=0;//循环







//2
unsigned char life2=0;
unsigned char life2X=0;
int cnt2=0;
int cnt2X=0;
unsigned char his2=1;
unsigned char cur2=1;









//3   雨滴传感器
unsigned char life3=0;
unsigned char life3X=0;
int cnt3=0;
int cnt3X=0;
unsigned char his3=1;
unsigned char cur3=1;










//系统初始化
void System_init()
{

  Serial.begin(9600);//串口调试专用
  Serial.print("system loading...");
  //输入
  pinMode(IN1, INPUT_PULLUP);  
  pinMode(IN2, INPUT_PULLUP);  
  pinMode(IN3, INPUT_PULLUP);  

 
  
  //电机控制接口
  //L298-1
  pinMode(MT1_IN1, OUTPUT); //1
  pinMode(MT1_IN2, OUTPUT); 
  
  pinMode(MT2_IN3, OUTPUT); //2
  pinMode(MT2_IN4, OUTPUT); 
  
  //L298-2
  pinMode(MT3_IN1, OUTPUT); //3
  pinMode(MT3_IN2, OUTPUT); 

  pinMode(MT4_IN3, OUTPUT); //4
  pinMode(MT4_IN4, OUTPUT); 

  //L298-3
  pinMode(MT5_IN1, OUTPUT); //5
  pinMode(MT5_IN2, OUTPUT); 

  pinMode(MT6_IN3, OUTPUT); //6
  pinMode(MT6_IN4, OUTPUT); 

  pinMode(MT7_IN1, OUTPUT); //7
  pinMode(MT7_IN2, OUTPUT); 



  //init
  //1
  lifeA1=0;
  lifeA2=0;
  cntA1=0;
  cntA2=0;
  his1=1;
  cur1=1;
  XUNHUANX=0;




  
//2
  life2=0;
  cnt2=0;
  his2=1;
  cur2=1;


//3
  life3=0;
  cnt3=0;
  his3=1;
  cur3=1;



  

  



  
}


void system_tick()//10ms
{
 delay(10);  
}

  void setup ()
{
  System_init();
}

//1#
void zheng1()
{
  digitalWrite(MT1_IN1, HIGH);
  digitalWrite(MT1_IN2, LOW);
}
void fan1()
{
  digitalWrite(MT1_IN1, LOW);
  digitalWrite(MT1_IN2, HIGH);
}
void stop1()
{
  digitalWrite(MT1_IN1, LOW);
  digitalWrite(MT1_IN2, LOW);
 }
//2#
void zheng2()
{
  digitalWrite(MT2_IN3, HIGH);
  digitalWrite(MT2_IN4, LOW);
}
void fan2()
{
  digitalWrite(MT2_IN3, LOW);
  digitalWrite(MT2_IN4, HIGH);
}
void stop2()
{
  digitalWrite(MT2_IN3, LOW);
  digitalWrite(MT2_IN4, LOW);
 }

 
 //3#
void zheng3()
{
  digitalWrite(MT3_IN1, HIGH);
  digitalWrite(MT3_IN2, LOW);
}
void fan3()
{
  digitalWrite(MT3_IN1, LOW);
  digitalWrite(MT3_IN2, HIGH);
}
void stop3()
{
  digitalWrite(MT3_IN1, LOW);
  digitalWrite(MT3_IN2, LOW);
 }
 //4#
void zheng4()
{
  digitalWrite(MT4_IN3, HIGH);
  digitalWrite(MT4_IN4, LOW);
}
void fan4()
{
  digitalWrite(MT4_IN3, LOW);
  digitalWrite(MT4_IN4, HIGH);
}
void stop4()
{
   digitalWrite(MT4_IN3, LOW);
   digitalWrite(MT4_IN4, LOW); 
 }


 
 //5#
void zheng5()
{
   digitalWrite(MT5_IN1, HIGH);
   digitalWrite(MT5_IN2, LOW); 
}
void fan5()
{
  digitalWrite(MT5_IN1, LOW);
  digitalWrite(MT5_IN2, HIGH); 
}
void stop5()
{
   digitalWrite(MT5_IN1, LOW);
   digitalWrite(MT5_IN2, LOW); 
 }
 //6#
void zheng6()
{
  digitalWrite(MT6_IN3, HIGH);
  digitalWrite(MT6_IN4, LOW); 
}
void fan6()
{
  digitalWrite(MT6_IN3, LOW);
  digitalWrite(MT6_IN4, HIGH); 
}
void stop6()
{
  digitalWrite(MT6_IN3, LOW);
  digitalWrite(MT6_IN4, LOW);  
 }
 //7#
void zheng7()
{
  digitalWrite(MT7_IN1, HIGH);
  digitalWrite(MT7_IN2, LOW); 
}
void fan7()
{
  digitalWrite(MT7_IN1, LOW);
  digitalWrite(MT7_IN2, HIGH); 
}
void stop7()
{
  digitalWrite(MT7_IN1, LOW);
  digitalWrite(MT7_IN2, LOW);  
 }
 
//自检测试程序
void self_check()
{

  if((digitalRead(IN1))==LOW)
  {
    zheng1();
  }
   else
   {
    fan1();
    }

      if((digitalRead(IN2))==LOW)
  {
    zheng2();
  }
   else
   {
    fan2();
    }

      if((digitalRead(IN3))==LOW)
  {
    zheng3();
  }
   else
   {
    fan3();
    }

     
  /*
  digitalWrite(MT1_IN1, HIGH);
  digitalWrite(MT1_IN2, HIGH);
  
  digitalWrite(MT2_IN3, HIGH);
  digitalWrite(MT2_IN4, HIGH);

  digitalWrite(MT3_IN1, HIGH);
  digitalWrite(MT3_IN2, HIGH);
  
  digitalWrite(MT4_IN3, HIGH);
  digitalWrite(MT4_IN4, HIGH);

  digitalWrite(MT5_IN1, HIGH);
  digitalWrite(MT5_IN2, HIGH);
  
  digitalWrite(MT6_IN3, HIGH);
  digitalWrite(MT6_IN4, HIGH);


  
  system_tick();
  digitalWrite(MT1_IN1, LOW);
  digitalWrite(MT1_IN2, LOW);
  
  digitalWrite(MT2_IN3, LOW);
  digitalWrite(MT2_IN4, LOW);

  digitalWrite(MT3_IN1, LOW);
  digitalWrite(MT3_IN2, LOW);
  digitalWrite(MT4_IN3, LOW);
  digitalWrite(MT4_IN4, LOW);

  digitalWrite(MT5_IN1, LOW);
  digitalWrite(MT5_IN2, LOW);
  digitalWrite(MT6_IN3, LOW);
  digitalWrite(MT6_IN4, LOW);






  
  system_tick();
  */
  //zheng1();
 // fan1();
 //stop1();

//zheng2();
 // fan2();
 //stop2();

 //zheng3();
 // fan3();
 //stop3();

 //zheng4();
 // fan4();
 //stop4();

 //zheng5();
 //fan5();
 //stop5();

 //zheng6();
 // fan6();
 //stop6();




  
 }


 void key_scan()
 {

  //1#
  if(lifeA1==0&&lifeA2==0)
  {
   //1
    if((digitalRead(IN1))==LOW)
   {
    delay(1);
     if((digitalRead(IN1))==LOW)
     {
      
      cur1=0;
      }
    
   
  }
   else
   {
    cur1=1;
    }
    if(cur1!=his1)//发生变化
    {
        his1=cur1;
        if(cur1==1)
        {
        cntA1=0;
        cntA2=0;
        lifeA1=1;
        lifeA2=1;  
        zheng1(); 
        zheng2();
        }
     }
 }
///////////////////////////////////////////
   //2
     ///执行结束后进入结束触发动作
     if(life2X==1&&life2==0)
    {

  
    if((digitalRead(IN2))==HIGH)
   {
    delay(1);
     if((digitalRead(IN2))==HIGH)
     {
      life2X=2;//
      cnt2X=0;
      fan5();
      
      
     }
      
     
      }
    
   
  
      
      
      
    }

    
   if(life2==0&&life2X==0)
   {
    if((digitalRead(IN2))==LOW)
   {
    delay(1);
     if((digitalRead(IN2))==LOW)
     {
      
      cur2=0;
      }
    
   
  }
   else
   {
    cur2=1;
    }
  





    
    if(cur2!=his2)//发生变化
    {
      his2=cur2;

      if(cur2==0)//发生触发动作  下降沿
      {
       
        cnt2=0;
        life2=1;
        zheng5();
        life2X=1;
       
        
       }   
    





        
     }
 }
///////////////////////////////////////////
   //3
   ///执行结束后进入结束触发动作


    
   if(life3==0&&life3X==0)
   {
    if((digitalRead(IN3))==LOW)
   {
    delay(1);
     if((digitalRead(IN3))==LOW)
     {
      
      cur3=0;
      }
    
   
  }
   else
   {
    cur3=1;
    }
  





    
    if(cur3!=his3)//发生变化
    {
      his3=cur3;

      if(cur3==0)//发生触发动作  下降沿
      {
       
        cnt3=0;
        life3=1;
        zheng7();
        life3X=1;
       
        
       }   
    





        
     }
 }
 
///////////////////////////////////////////
  




    
  
  
  }

  //
void APP()
{
 //同步1
if(lifeA1==1)
{
   cntA1++;
  if( cntA1>=TIMEA)
  {
     cntA1=0;
    lifeA1=2;
    fan1();
    
    
   }
 }
 else if(lifeA1==2)
 {
    cntA1++;
   if( cntA1>=TIMEA)
  {
     cntA1=0;
    lifeA1=3;
    zheng1();
    
    
   }
  
  
  }
 else if(lifeA1==3)
 {
    cntA1++;
   if( cntA1>=TIMEA)
  {
    cntA1=0;
    lifeA1=4;
    fan1();
    
    
    
   }
  
  
  }
 else if(lifeA1==4)
 {
   cntA1++;
   if(cntA1>=TIMEA)
  {
    cntA1=0;
    lifeA1=0;
    stop1();
    
    
    
   }
  
  
  }
 ///同步2
 //循环执行








 

if(lifeA2==1)
{
  cntA2++;
   if( cntA2>=TIMEB)
  {
    cntA2=0;
    lifeA2=2;
    fan2();
    
    
    
   } 
  
}
else if(lifeA2==2)
{
   cntA2++;
   if( cntA2>=TIMEB)
   {
    cntA2=0;
    lifeA2=3;
    stop2();
    zheng3();
    

    
    
    
    
   } 
  
  
  
 }
 else if(lifeA2==3)
{
   cntA2++;
   if( cntA2>=TIMEB)
   {
    cntA2=0;
    lifeA2=4;
    stop2();
    fan3();
    

    
    
    
    
   } 
  
  
  
 }
 else if(lifeA2==4)
{
   cntA2++;
   if( cntA2>=TIMEB)
   {
    cntA2=0;
    lifeA2=5;
    stop2();
    stop3();
    zheng4();
    

    
    
    
    
   } 
  
  
  
 }
 else if(lifeA2==5)
{
   cntA2++;
   if( cntA2>=TIMEB)
   {
    cntA2=0;
    lifeA2=6;
    stop2();
    fan4();
    
    

    
    
    
    
   } 
  
  
  
 }
 else if(lifeA2==6)
{
   cntA2++;
   if( cntA2>=TIMEB)
   {
    
    
    XUNHUANX++;
    if(XUNHUANX>=LOOPX)
{
  XUNHUANX=0;
  lifeA2=0;
  cntA2=0;
    
   
    stop4();
    
  
  
  
 }
 else
 {
    cntA2=0;
    lifeA2=1;
    stop2();
    stop4();
    zheng2();
  }

    
    

    
    
    
    
   } 
  
  
  
 }

 ////////////////////////////////
 //土壤湿度传感器
 if(life2==1)
 {
  cnt2++;
  if(cnt2>=DELAY2)
  {
    cnt2=0;
    stop5();
    zheng6();
    life2=2;
    
   }
  
  }
  else if(life2==2)
  {
    
     cnt2++;
  if(cnt2>=DELAY2)
  {
    cnt2=0;
    stop5();
    stop6();
   
    life2=0;
    
   }
    
    
    }

    ///////
     if(life2==0)
    {

      if(life2X==2)
      {
        cnt2X++;
          if(cnt2X>=DELAY2)
         {
            cnt2X=0;
            life2X=3;
            stop5();
            fan6();
    
        }
        
        
        
        }
        else if(life2X==3)
        {
          cnt2X++;
          if(cnt2X>=DELAY2)
         {
            cnt2X=0;
            life2X=0;
            stop5();
            stop6();
    
        }
          
          
          
          
          
          }
        
      
      
      
      
      }

 




 ////////////////////////////////
 //雨滴传感器
 if(life3==1)
 {
  cnt3++;
  if(cnt3>=DELAY3)
  {
    cnt3=0;
    
    fan7();
    life3=2;
    
   }
  
  }
  else if(life3==2)
  {
    
     cnt3++;
  if(cnt3>=DELAY3)
  {
    cnt3=0;
      if((digitalRead(IN3))==HIGH)
   {
    delay(1);
     if((digitalRead(IN3))==HIGH)
     {
      life3X=0;//
      cnt3X=0;
       life3=0;
       
      stop7();
      
      
     }
      
     
      }
      else
      {
        zheng7();
        life3=1;
        
        
        }


    
    
    
   }
    
    
    }

    ///////


 






 
 
 

 
 
  
 

    

  
  
  }
void loop()
{
 // self_check();
 system_tick();
 key_scan();
 APP();
 

  
 
  


   
  









  
  
}

