#include <QtGui>
#include <iostream>
#include "ProcessorWindow.h"

ProcessorWindow::ProcessorWindow()
{
   // The main layout
   QVBoxLayout* mainLayout = new QVBoxLayout();
   
   // Ensure a starting empty vector
   layouts.clear();
   boxOptions.clear();
   expandableButtons.clear();
   itemPrices.clear();
   productImages.clear();
   pixMaps.clear();
   
   // Load our assets
   loadAssets();
   
   // Instantiate all of our vectors and populate them
   for (int i = 0; i < 6; ++i)
   {
      layouts.push_back(new QHBoxLayout());
      boxOptions.push_back(new QCheckBox());
      expandableButtons.push_back(new QPushButton());
      itemPrices.push_back(new QLabel());
      productImages.push_back(new QLabel());
      
      productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 10, Qt::KeepAspectRatio, Qt::SmoothTransformation));
      expandableButtons[i]->setText("View Now");
      expandableButtons[i]->setStyleSheet("text-align:right; border:0px;");
      boxOptions[i]->setFixedWidth(200);
      
      layouts[i]->addWidget(productImages[i]);
      layouts[i]->addWidget(boxOptions[i]);
      layouts[i]->addWidget(itemPrices[i]);
      layouts[i]->addWidget(expandableButtons[i]);
      
      mainLayout->addLayout(layouts[i]);
   }
   
   // Set our values
   itemPrices[0]->setText("$259.99");
   itemPrices[1]->setText("$159.99");
   itemPrices[2]->setText("$109.99");
   itemPrices[3]->setText("$499.99");
   itemPrices[4]->setText("$339.99");
   itemPrices[5]->setText("$179.99");
   
   boxOptions[0]->setText("High End AMD CPU");
   boxOptions[1]->setText("Middle Range AMD CPU");
   boxOptions[2]->setText("Low End AMD CPU");
   boxOptions[3]->setText("High End Intel CPU");
   boxOptions[4]->setText("Mid Range Intel CPU");
   boxOptions[5]->setText("Low End Intel CPU");
   
   this->setLayout(mainLayout);
   
   // Connect our check boxes
   connect(boxOptions[0], SIGNAL(stateChanged(int)), this, SLOT(updateBoxOne(int)));
   connect(boxOptions[1], SIGNAL(stateChanged(int)), this, SLOT(updateBoxTwo(int)));
   connect(boxOptions[2], SIGNAL(stateChanged(int)), this, SLOT(updateBoxThree(int)));
   connect(boxOptions[3], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFour(int)));
   connect(boxOptions[4], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFive(int)));
   connect(boxOptions[5], SIGNAL(stateChanged(int)), this, SLOT(updateBoxSix(int)));
   
   // Connect our expandable buttons
   connect(expandableButtons[0], SIGNAL(clicked()), this, SLOT(openWindowOne()));
   connect(expandableButtons[1], SIGNAL(clicked()), this, SLOT(openWindowTwo()));
   connect(expandableButtons[2], SIGNAL(clicked()), this, SLOT(openWindowThree()));
   connect(expandableButtons[3], SIGNAL(clicked()), this, SLOT(openWindowFour()));
   connect(expandableButtons[4], SIGNAL(clicked()), this, SLOT(openWindowFive()));
   connect(expandableButtons[5], SIGNAL(clicked()), this, SLOT(openWindowSix()));
}

ProcessorWindow::~ProcessorWindow()
{
}

void ProcessorWindow::updateBoxOne(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxTwo(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxThree(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxFour(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[4]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxFive(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
      boxOptions[5]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::updateBoxSix(int newState)
{
   // Ensure removal of all other check marks
   if (newState == 2)
   {
      boxOptions[0]->setCheckState(Qt::Unchecked);
      boxOptions[1]->setCheckState(Qt::Unchecked);
      boxOptions[2]->setCheckState(Qt::Unchecked);
      boxOptions[3]->setCheckState(Qt::Unchecked);
      boxOptions[4]->setCheckState(Qt::Unchecked);
   }
}

void ProcessorWindow::resizeEvent(QResizeEvent* resizeEvent)
{
   // Handle the resize of the window for the assets
   for (int i = 0; i < 6; ++i)
      if (!(pixMaps[i].isNull()))
         productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 6, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void ProcessorWindow::loadAssets()
{
   // Let's get the location of our images
   QDir workingDirectory(QApplication::applicationFilePath());
   workingDirectory.cdUp();
   workingDirectory.cdUp();
   QString imagesDirectory = workingDirectory.absolutePath() + "/assets/";
   
   // Instantiate our images and put them in pixmaps
   std::vector<QImage> images;
   
   images.push_back(QImage(imagesDirectory + "HighEndAmdCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "MidRangeAmdCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeAmdCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "HighEndIntelCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "MidRangeIntelCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeIntelCpu.jpeg"));
   
   for (int i = 0; i < 6; ++i)
      pixMaps.push_back(QPixmap(QPixmap::fromImage(images[i])));
}

void ProcessorWindow::openWindowOne()
{
}

void ProcessorWindow::openWindowTwo()
{
}

void ProcessorWindow::openWindowThree()
{
}

void ProcessorWindow::openWindowFour()
{
}

void ProcessorWindow::openWindowFive()
{
}

void ProcessorWindow::openWindowSix()
{
}
