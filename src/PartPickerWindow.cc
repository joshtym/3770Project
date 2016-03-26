#include <QtGui>
#include <iostream>
#include "PartPickerWindow.h"

PartPickerWindow::PartPickerWindow()
{
   // Instantiate our tabBar
   tabBar = new QTabWidget();
   
   tabPages.clear();
   
   for (int i = 0; i < 4; ++i)
      tabPages.push_back(new QScrollArea());
   
   cpuWindow = new ProcessorWindow();
   mbWindow = new MotherboardWindow();
   
   tabPages[0]->setWidget(new ProcessorWindow());
   tabPages[1]->setWidget(new MotherboardWindow());
   
   tabBar->addTab(tabPages[0], "CPU");
   tabBar->addTab(tabPages[1], "Motherboard");
   
   // Set this to be the central widget
   setCentralWidget(tabBar);
}
