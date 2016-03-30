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
   specWindows.clear();
   
   // Load our assets
   loadAssets();
   
   // Instantiate all of our vectors and populate them
   for (int i = 0; i < 6; ++i)
   {
      boxOptions.push_back(new QCheckBox());
      expandableButtons.push_back(new QPushButton());
      itemPrices.push_back(new QLabel());
      productImages.push_back(new QLabel());
      specWindows.push_back(new SpecificationWindow());
      
      productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 10, Qt::KeepAspectRatio, Qt::SmoothTransformation));
      expandableButtons[i]->setText("View Now");
      expandableButtons[i]->setStyleSheet("text-align:right; border:0px;");
      boxOptions[i]->setFixedWidth(200);
      specWindows[i]->hide();
   }
   
   // Make our layouts. Odd layouts not initially visible since widgets hidden
   for (int i = 0; i < 12; ++i)
   {
      layouts.push_back(new QHBoxLayout());
      
      if ((i % 2) == 0)
      {
         layouts[i]->addWidget(productImages[i/2]);
         layouts[i]->addWidget(boxOptions[i/2]);
         layouts[i]->addWidget(itemPrices[i/2]);
         layouts[i]->addWidget(expandableButtons[i/2]);
      }
      else
         layouts[i]->addWidget(specWindows[i/2]);
         
      mainLayout->addLayout(layouts[i]);
   }
   
   /// TODO : Double the amount of layouts and add inner versions for specifications (Maybe reviews)?
   
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
   if (specWindows[0]->isHidden())
      specWindows[0]->show();
   else
      specWindows[0]->hide();
}

void ProcessorWindow::openWindowTwo()
{
   if (specWindows[1]->isHidden())
      specWindows[1]->show();
   else
      specWindows[1]->hide();
}

void ProcessorWindow::openWindowThree()
{
   if (specWindows[2]->isHidden())
      specWindows[2]->show();
   else
      specWindows[2]->hide();
}

void ProcessorWindow::openWindowFour()
{
   if (specWindows[3]->isHidden())
      specWindows[3]->show();
   else
      specWindows[3]->hide();
}

void ProcessorWindow::openWindowFive()
{
   if (specWindows[4]->isHidden())
      specWindows[4]->show();
   else
      specWindows[4]->hide();
}

void ProcessorWindow::openWindowSix()
{
   if (specWindows[5]->isHidden())
      specWindows[5]->show();
   else
      specWindows[5]->hide();
}
