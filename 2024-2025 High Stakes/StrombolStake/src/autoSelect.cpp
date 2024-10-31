/*#include "vex.h"
#include <autons.h>
#include "autoSelect.h"
using namespace vex;
    void selectScreen(){
        //printable surface is 480x272 pixels
        Brain.Screen.clearScreen();
        Brain.Screen.printAt(5, 40, "Battery Percentage:");
        Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
        Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
        Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
        Brain.Screen.setFillColor("#E6E6FA");//lavander boxes
        Brain.Screen.drawRectangle(240, 0, 60, 60);// left arrow box, drawRectangle(x, y, width, hight, hue) 
        Brain.Screen.drawRectangle(240, 65, 60, 60);// right arrow box, hue color is determined fro 1 - 359
        Brain.Screen.setPenColor("#FFD700");//gold text
        Brain.Screen.printAt(230, 5, "Left side of allinace stake");
        Brain.Screen.printAt(230, 70, "Right side of allinace stake");
        Brain.Screen.setFillColor("FFA500");// orange boxes for pus and minus boxes
        Brain.Screen.drawRectangle(200, 309, 36, 36, 60);// make box for plus
        Brain.Screen.drawRectangle(200, 437, 36, 36, 40);// make box for minus
        Brain.Screen.setFillColor("#000000");
        Brain.Screen.drawLine(200, 436, 236, 436);// sepertion line between plus and minus
        Brain.Screen.setFillColor("#ffffff");// white minus and plus symbols
        Brain.Screen.drawRectangle(205, 415, 18, 5, 1);// make plus
        Brain.Screen.drawRectangle(218, 405, 5, 18, 1);// make plus
        Brain.Screen.drawRectangle(205, 454, 18, 5, 1);// make minus
    }
    void leftSelected(){
        bool leftSelecteds = true;
        bool rightSelecteds = false;
        Brain.Screen.setFillColor("#E6E6FA");//lavander boxes
        Brain.Screen.drawRectangle(240, 0, 60, 60);// left arrow box, drawRectangle(x, y, width, hight, hue) 
        Brain.Screen.drawRectangle(240, 65, 60, 60);// right arrow box, hue color is determined fro 1 - 359
        Brain.Screen.setPenColor("#FFD700");//gold text
        Brain.Screen.printAt(230, 5, "Left side of allinace stake");
        Brain.Screen.printAt(230, 70, "Right side of allinace stake");
        Brain.Screen.setFillColor("#FFA500");
        Brain.Screen.setPenWidth(10);
        Brain.Screen.drawLine(240, 0, 272, 60);//draw border around rectangle
        Brain.Screen.drawLine(240, 0, 212, 60);//draw border around rectangle
        Brain.Screen.drawLine(240, 60, 272, 60);//draw border around rectangle
        Brain.Screen.drawLine(300, 60, 272, 0);//draw border around rectangle
        Brain.Screen.setPenWidth(1);
    }
    void rightSelected(){
        bool leftSelecteds = false;
        bool rightSelecteds = true;
        Brain.Screen.setFillColor("#E6E6FA");//lavander boxes
        Brain.Screen.drawRectangle(240, 0, 60, 60);// left arrow box, drawRectangle(x, y, width, hight, hue) 
        Brain.Screen.drawRectangle(240, 65, 60, 60);// right arrow box, hue color is determined fro 1 - 359
        Brain.Screen.setPenColor("#FFD700");//gold text
        Brain.Screen.printAt(230, 5, "Left side of allinace stake");
        Brain.Screen.printAt(230, 70, "Right side of allinace stake");
        Brain.Screen.setFillColor("#FFA500");
        Brain.Screen.setPenWidth(10);
        Brain.Screen.drawLine(240, 65, 300, 125);//draw border around rectangle
        Brain.Screen.drawLine(240, 65, 240, 125);//draw border around rectangle
        Brain.Screen.drawLine(240, 125, 300, 125);//draw border around rectangle
        Brain.Screen.drawLine(300, 125, 300, 65);//draw border around rectangle
        Brain.Screen.setPenWidth(1);
    }
    void plusSelected(){
        bool plusSelecteds = true;
        bool minusSelecteds = false;
        Brain.Screen.drawRectangle(200, 309, 36, 36, 60);// make box for plus
        Brain.Screen.drawRectangle(200, 437, 36, 36, 40);// make box for minus
        Brain.Screen.setFillColor("#000000");
        Brain.Screen.drawLine(200, 436, 236, 436);// sepertion line between plus and minus
        Brain.Screen.setFillColor("#ffffff");// white minus and plus symbols
        Brain.Screen.drawRectangle(205, 415, 18, 5, 1);// make plus
        Brain.Screen.drawRectangle(218, 405, 5, 18, 1);// make plus
        Brain.Screen.drawRectangle(205, 454, 18, 5, 1);// make minus
        Brain.Screen.setPenWidth(10);
        Brain.Screen.setPenColor("FFA500");
        Brain.Screen.drawLine(200, 309, 236, 309);//draw border around rectangle
        Brain.Screen.drawLine(236, 309, 236, 345);//draw border around rectangle
        Brain.Screen.drawLine(236, 345, 200, 345);//draw border around rectangle
        Brain.Screen.drawLine(200, 345, 200, 309);//draw border around rectangle
    }
    void minusSelected(){
        bool plusSelecteds = false;
        bool minusSelecteds = true;
        Brain.Screen.drawRectangle(200, 309, 36, 36, 60);// make box for plus
        Brain.Screen.drawRectangle(200, 437, 36, 36, 40);// make box for minus
        Brain.Screen.setFillColor("#000000");
        Brain.Screen.drawLine(200, 436, 236, 436);// sepertion line between plus and minus
        Brain.Screen.setFillColor("#ffffff");// white minus and plus symbols
        Brain.Screen.drawRectangle(205, 415, 18, 5, 1);// make plus
        Brain.Screen.drawRectangle(218, 405, 5, 18, 1);// make plus
        Brain.Screen.drawRectangle(205, 454, 18, 5, 1);// make minus
        Brain.Screen.setPenWidth(10);
        Brain.Screen.setPenColor("FFA500");
        Brain.Screen.drawLine(200, 437, 236, 309);//draw border around rectangle
        Brain.Screen.drawLine(236, 437, 236, 345);//draw border around rectangle
        Brain.Screen.drawLine(236, 401, 200, 345);//draw border around rectangle
        Brain.Screen.drawLine(200, 401, 200, 309);//draw border around rectangle
    }
    */
    /*
    fancy select
    while(!auto_started){
    selectScreen();
    int xSelect = Brain.Screen.xPosition();
    int ySelect = Brain.Screen.yPosition();
    if(xSelect <= 300 && xSelect >= 240 && ySelect >= 0 && ySelect <= 60 || leftSelecteds){
      leftSelected();
    }
    else if(xSelect <= 300 && xSelect >= 240 && ySelect >= 65 && ySelect <= 125 || rightSelecteds){
      rightSelected();
    }
    if(xSelect <= 200 && xSelect >= 236 && ySelect >= 309 && ySelect <= 345 || plusSelecteds){
      plusSelected();
    }
    else if(xSelect <= 200 && xSelect >= 236 && ySelect >= 437 && ySelect <= 473 || minusSelecteds){
      minusSelected();
    }
    */
/*
    void jarSelect(){
        
        Brain.Screen.clearScreen();
        Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
        Brain.Screen.printAt(5, 40, "Battery Percentage:");
        Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
        Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
        Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
        Brain.Screen.printAt(5, 120, "Selected Auton:");
        switch(current_auton_selection){
        case 0:
            Brain.Screen.printAt(5, 140, "Auton 1");
            break;
        case 1:
            Brain.Screen.printAt(5, 140, "Auton 2");
            break;
        case 2:
            Brain.Screen.printAt(5, 140, "Auton 3");
            break;
        case 3:
            Brain.Screen.printAt(5, 140, "Auton 4");
            break;
        case 4:
            Brain.Screen.printAt(5, 140, "Auton 5");
            break;
        case 5:
            Brain.Screen.printAt(5, 140, "Auton 6");
            break;
        case 6:
            Brain.Screen.printAt(5, 140, "Auton 7");
            break;
        case 7:
            Brain.Screen.printAt(5, 140, "Auton 8");
            break;
        }
        if(Brain.Screen.pressing()){
        while(Brain.Screen.pressing()) {}
        current_auton_selection ++;
        } else if (current_auton_selection == 8){
        current_auton_selection = 0;
        }
        task::sleep(10);
    }
    */
    /*
    fancy auton selecto
    
  if(plusSelecteds && leftSelecteds){
    armDesiredValue = 500;// testing armPID
    leftPos();
  }
  else if(plusSelecteds && rightSelecteds){
    rightPos();
  }
  else if(minusSelecteds && leftSelecteds){
    leftNeg();
  }
  else if(minusSelecteds && rightSelecteds){
    rightNeg();
  }
  */
  /*
    void jarAutoSelect(){
        switch(current_auton_selection){ 
        case 0:
        drive_test();
        break;
        case 1:         
        drive_test();
        break;
        case 2:
        turn_test();
        break;
        case 3:
        swing_test();
        break;
        case 4:
        full_test();
        break;
        case 5:
        odom_test();
        break;
        case 6:
        tank_odom_test();
        break;
        case 7:
        holonomic_odom_test();
        break;
        }
    }
    */