#include <QtGui>
#include "RamWindow.h"

RamWindow::RamWindow()
{
   // The main layout
   QVBoxLayout* mainLayout = new QVBoxLayout();
   
   // Variable instantiations
   currentlyCheckedBox = -1;
   
   // Ensure a starting empty vector
   layouts.clear();
   boxOptions.clear();
   expandableButtons.clear();
   itemPriceLabels.clear();
   productImages.clear();
   pixMaps.clear();
   specWindows.clear();
   itemPrices.clear();
   
   // Load our assets
   loadAssets();
   
   // Instantiate all of our vectors and populate them
   for (int i = 0; i < 6; ++i)
   {
      boxOptions.push_back(new QCheckBox());
      expandableButtons.push_back(new QPushButton());
      itemPriceLabels.push_back(new QLabel());
      productImages.push_back(new QLabel());
      specWindows.push_back(new SpecificationWindow());
      specWindows[i]->addWidget(new QLabel("Test"));
      
      productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 10, Qt::KeepAspectRatio, Qt::SmoothTransformation));
      expandableButtons[i]->setText("View Now");
      expandableButtons[i]->setStyleSheet("text-align:right; border:0px;");
      boxOptions[i]->setFixedWidth(250);
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
         layouts[i]->addWidget(itemPriceLabels[i/2]);
         layouts[i]->addWidget(expandableButtons[i/2]);
      }
      else
         layouts[i]->addWidget(specWindows[i/2]);
         
      mainLayout->addLayout(layouts[i]);
   }
   
   /// TODO : Double the amount of layouts and add inner versions for specifications (Maybe reviews)?
   
   // Set our values
   itemPriceLabels[0]->setText("$399.99");
   itemPrices.push_back(399.99);
   itemPriceLabels[1]->setText("$299.99");
   itemPrices.push_back(299.99);
   itemPriceLabels[2]->setText("$102.00");
   itemPrices.push_back(102.99);
   itemPriceLabels[3]->setText("$169.99");
   itemPrices.push_back(169.99);
   itemPriceLabels[4]->setText("$34.99");
   itemPrices.push_back(34.99);
   itemPriceLabels[5]->setText("$69.99");
   itemPrices.push_back(69.99);
   
   boxOptions[0]->setText("High End RAM #1");
   boxOptions[1]->setText("High End RAM #2");
   boxOptions[2]->setText("Mid Range RAM #1");
   boxOptions[3]->setText("Mid Range RAM #2");
   boxOptions[4]->setText("Low Range RAM #1");
   boxOptions[5]->setText("Low Range RAM #1");
   
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

RamWindow::~RamWindow()
{
}

void RamWindow::updateBoxOne(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 0 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[0], 0);
      }
      else
         emit sendNewBoxUpdate(itemPrices[0], 0);
         
      currentlyCheckedBox = 0;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[0]);
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxTwo(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 1 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[1], 0);
      }
      else
         emit sendNewBoxUpdate(itemPrices[1], 0);
         
      currentlyCheckedBox = 1;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[1]);
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxThree(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 2 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[2], 0);
      }
      else
         emit sendNewBoxUpdate(itemPrices[2], 0);
         
      currentlyCheckedBox = 2;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[2]);
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxFour(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 3 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[3], 0);
      }
      else
         emit sendNewBoxUpdate(itemPrices[3], 0);
         
      currentlyCheckedBox = 3;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[3]);
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxFive(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 4 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[4], 0);
      }
      else
         emit sendNewBoxUpdate(itemPrices[4], 0);
         
      currentlyCheckedBox = 4;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[4]);
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxSix(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 5 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[5], 0);
      }
      else
         emit sendNewBoxUpdate(itemPrices[5], 0);
         
      currentlyCheckedBox = 5;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[5]);
      currentlyCheckedBox = -1;
   }
}

void RamWindow::resizeEvent(QResizeEvent* resizeEvent)
{
   // Handle the resize of the window for the assets
   for (int i = 0; i < 6; ++i)
      if (!(pixMaps[i].isNull()))
         productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 6, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void RamWindow::loadAssets()
{
   // Let's get the location of our images
   QDir workingDirectory(QApplication::applicationFilePath());
   workingDirectory.cdUp();
   workingDirectory.cdUp();
   QString imagesDirectory = workingDirectory.absolutePath() + "/assets/";
   
   // Instantiate our images and put them in pixmaps
   std::vector<QImage> images;
   
   images.push_back(QImage(imagesDirectory + "high_range_hyperx_RAM.jpeg"));
   images.push_back(QImage(imagesDirectory + "high_range_Corsair_RAM.jpeg"));
   images.push_back(QImage(imagesDirectory + "mid_range_hyperx_RAM.jpeg"));
   images.push_back(QImage(imagesDirectory + "Mid_range_Corsair_RAM.jpeg"));
   images.push_back(QImage(imagesDirectory + "low_range_hyperx_RAM.jpeg"));
   images.push_back(QImage(imagesDirectory + "Low_range_Corsair_RAM.jpeg"));
   
   for (int i = 0; i < 6; ++i)
      pixMaps.push_back(QPixmap(QPixmap::fromImage(images[i])));
}

void RamWindow::openWindowOne()
{
   if (specWindows[0]->isHidden())
      specWindows[0]->show();
   else
      specWindows[0]->hide();
}

void RamWindow::openWindowTwo()
{
   if (specWindows[1]->isHidden())
      specWindows[1]->show();
   else
      specWindows[1]->hide();
}

void RamWindow::openWindowThree()
{
   if (specWindows[2]->isHidden())
      specWindows[2]->show();
   else
      specWindows[2]->hide();
}

void RamWindow::openWindowFour()
{
   if (specWindows[3]->isHidden())
      specWindows[3]->show();
   else
      specWindows[3]->hide();
}

void RamWindow::openWindowFive()
{
   if (specWindows[4]->isHidden())
      specWindows[4]->show();
   else
      specWindows[4]->hide();
}

void RamWindow::openWindowSix()
{
   if (specWindows[5]->isHidden())
      specWindows[5]->show();
   else
      specWindows[5]->hide();
}
