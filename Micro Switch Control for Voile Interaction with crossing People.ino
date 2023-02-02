//////////////////////////////////////////////////
// Arduino Mega 2560: Voile Interaction with the Crossing People 跟随互动程序
//算法设计完成
/////////////////////////////////////////////////


//输入
//压力传感输入接口 独立按键检测
const int IN1=2;//输入按键1
const int IN2=3;//输入按键2
const int IN3=4;//输入按键3
const int IN4=5;//输入按键4
const int IN5=6;//输入按键5
const int IN6=7;//输入按键6




//L298  -- 1#
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

//L298  -- 3#
//电机5
const int MT5_IN1=49;//
const int MT5_IN2=47;//
//电机6
const int MT6_IN3=45;//
const int MT6_IN4=43;//

#define TIMEX 500


//数据缓存
//1
unsigned char life1=0;
int cnt1=0;
unsigned char his1=1;
unsigned char cur1=1;

//2
unsigned char life2=0;
int cnt2=0;
unsigned char his2=1;
unsigned char cur2=1;

//3
unsigned char life3=0;
int cnt3=0;
unsigned char his3=1;
unsigned char cur3=1;

//4
unsigned char life4=0;
int cnt4=0;
unsigned char his4=1;
unsigned char cur4=1;


//5
unsigned char life5=0;
int cnt5=0;
unsigned char his5=1;
unsigned char cur5=1;


//6
unsigned char life6=0;
int cnt6=0;
unsigned char his6=1;
unsigned char cur6=1;








//系统初始化
void System_init()
{

  Serial.begin(9600);//串口调试专用
  Serial.print("system loading...");
  //输入
  pinMode(IN1, INPUT_PULLUP);  
  pinMode(IN2, INPUT_PULLUP);  
  pinMode(IN3, INPUT_PULLUP);  
  pinMode(IN4, INPUT_PULLUP);  
  pinMode(IN5, INPUT_PULLUP);  
  pinMode(IN6, INPUT_PULLUP);  
 
  
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



  //init
  //1
  life1=0;
  cnt1=0;
  his1=1;
  cur1=1;
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
//4
  life4=0;
  cnt4=0;
  his4=1;
  cur4=1;
//5
  life5=0;
  cnt5=0;
  his5=1;
  cur5=1;
//6
  life6=0;
  cnt6=0;
  his6=1;
  cur6=1;


  

  



  
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

      if((digitalRead(IN4))==LOW)
  {
    zheng4();
  }
   else
   {
    fan4();
    }

      if((digitalRead(IN5))==LOW)
  {
    zheng5();
  }
   else
   {
    fan5();
    }

      if((digitalRead(IN6))==LOW)
  {
    zheng6();
  }
   else
   {
    fan6();
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
  if(life1==0)
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

      if(cur1==0)//发生触发动作
      {
        zheng1();
        cnt1=0;
        life1=1;
        
       }     
     }
 }
///////////////////////////////////////////
   //2
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

      if(cur2==0)//发生触发动作
      {
        zheng2();
        cnt2=0;
        life2=1;
        
       }     
     }
 
///////////////////////////////////////////
   //3
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

      if(cur3==0)//发生触发动作
      {
        zheng3();
        cnt3=0;
        life3=1;
        
       }     
     }
 
///////////////////////////////////////////
   //4
    if((digitalRead(IN4))==LOW)
   {
    delay(1);
     if((digitalRead(IN4))==LOW)
     {
      
      cur4=0;
      }
    
   
  }
   else
   {
    cur4=1;
    }
    if(cur4!=his4)//发生变化
    {
      his4=cur4;

      if(cur4==0)//发生触发动作
      {
        zheng4();
        cnt4=0;
        life4=1;
        
       }     
     }
 
///////////////////////////////////////////
   //5
    if((digitalRead(IN5))==LOW)
   {
    delay(1);
     if((digitalRead(IN5))==LOW)
     {
      
      cur5=0;
      }
    
   
  }
   else
   {
    cur5=1;
    }
    if(cur5!=his5)//发生变化
    {
      his5=cur5;

      if(cur5==0)//发生触发动作
      {
        zheng5();
        cnt5=0;
        life5=1;
        
       }     
     }
 
///////////////////////////////////////////
   //6
    if((digitalRead(IN6))==LOW)
   {
    delay(1);
     if((digitalRead(IN6))==LOW)
     {
      
      cur6=0;
      }
    
   
  }
   else
   {
    cur6=1;
    }
    if(cur6!=his6)//发生变化
    {
      his6=cur6;

      if(cur6==0)//发生触发动作
      {
        zheng6();
        cnt6=0;
        life6=1;
        
       }     
     }
 
///////////////////////////////////////////




    
  
  
  }
void APP()
{
  //1
   if(life1==1)
   {
    cnt1++;
    if(cnt1>=TIMEX)
    {

      cnt1=0;
      life1=2;
      fan1();  
     }
    }
    else if(life1==2)
    {
        cnt1++;
      if(cnt1>=TIMEX)
      {
        cnt1=0;
        life1=0;
        stop1();     
       } 
     }
     //
  //2
   if(life2==1)
   {
    cnt2++;
    if(cnt2>=TIMEX)
    {

      cnt2=0;
      life2=2;
      fan2();  
     }
    }
    else if(life2==2)
    {
        cnt2++;
      if(cnt2>=TIMEX)
      {
        cnt2=0;
        life2=0;
        stop2();     
       } 
     }
     //
       //3
   if(life3==1)
   {
    cnt3++;
    if(cnt3>=TIMEX)
    {

      cnt3=0;
      life3=2;
      fan3();  
     }
    }
    else if(life3==2)
    {
        cnt3++;
      if(cnt3>=TIMEX)
      {
        cnt3=0;
        life3=0;
        stop3();     
       } 
     }
     //
       //4
   if(life4==1)
   {
    cnt4++;
    if(cnt4>=TIMEX)
    {

      cnt4=0;
      life4=2;
      fan4();  
     }
    }
    else if(life4==2)
    {
        cnt4++;
      if(cnt4>=TIMEX)
      {
        cnt4=0;
        life4=0;
        stop4();     
       } 
     }
     //
       //5
   if(life5==1)
   {
    cnt5++;
    if(cnt5>=TIMEX)
    {

      cnt5=0;
      life5=2;
      fan5();  
     }
    }
    else if(life5==2)
    {
        cnt5++;
      if(cnt5>=TIMEX)
      {
        cnt5=0;
        life5=0;
        stop5();     
       } 
     }
     //
       //6
   if(life6==1)
   {
    cnt6++;
    if(cnt6>=TIMEX)
    {

      cnt6=0;
      life6=2;
      fan6();  
     }
    }
    else if(life6==2)
    {
        cnt6++;
      if(cnt6>=TIMEX)
      {
        cnt6=0;
        life6=0;
        stop6();     
       } 
     }
     //
    

  
  
  }
void loop()
{
 // self_check();
 system_tick();
 key_scan();
 APP();
 

  
 
  


   
  









  
  
}
