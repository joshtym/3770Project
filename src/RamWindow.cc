#include <QtGui>
#include "RamWindow.h"

RamWindow::RamWindow()
{
   // The main layout
   QVBoxLayout* mainLayout = new QVBoxLayout();
   
   // Variable instantiations
   currentlyCheckedBox = -1;
   currentAmount = 0;
   budgetAmount = 0;
   
   // Ensure a starting empty vector
   layouts.clear();
   boxOptions.clear();
   expandableButtons.clear();
   itemPriceLabels.clear();
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
      itemPriceLabels.push_back(new QLabel());
      productImages.push_back(new QLabel());
      specWindows.push_back(new SpecificationWindow());
      
      productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 10, Qt::KeepAspectRatio, Qt::SmoothTransformation));
      expandableButtons[i]->setText("View Now");
      expandableButtons[i]->setStyleSheet("text-align:right; border:0px;");
      boxOptions[i]->setMinimumWidth(200);
   }
   
   // Load specs
   loadSpecs();
   
   // Make our layouts. Odd layouts not initially visible since widgets hidden
   for (int i = 0; i < 6; ++i)
   {
      layouts.push_back(new QHBoxLayout());
      layouts[i]->addWidget(productImages[i]);
      layouts[i]->addWidget(boxOptions[i]);
      layouts[i]->addWidget(itemPriceLabels[i]);
      layouts[i]->addWidget(expandableButtons[i]);
         
      mainLayout->addLayout(layouts[i]);
   }
   
   // Set our values
   itemPriceLabels[0]->setText("$219.99");
   itemPrices.push_back(219.99);
   itemPriceLabels[1]->setText("$129.99");
   itemPrices.push_back(129.99);
   itemPriceLabels[2]->setText("$69.00");
   itemPrices.push_back(69.99);
   itemPriceLabels[3]->setText("$239.99");
   itemPrices.push_back(239.99);
   itemPriceLabels[4]->setText("$102.99");
   itemPrices.push_back(102.99);
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
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[0]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
            boxOptions[0]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
            currentlyCheckedBox = 0;
         }
      }
      else if (currentlyCheckedBox != 0)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[0]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
            boxOptions[0]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
            currentlyCheckedBox = 0;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[0], "");
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxTwo(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[1]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
            boxOptions[1]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
            currentlyCheckedBox = 1;
         }
      }
      else if (currentlyCheckedBox != 1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[1]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
            boxOptions[1]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
            currentlyCheckedBox = 1;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[1], "");
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxThree(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[2]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
            boxOptions[2]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
            currentlyCheckedBox = 2;
         }
      }
      else if (currentlyCheckedBox != 2)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[2]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
            boxOptions[2]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
            currentlyCheckedBox = 2;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[2], "");
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxFour(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[3]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
            boxOptions[3]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
            currentlyCheckedBox = 3;
         }
      }
      else if (currentlyCheckedBox != 3)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[3]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
            boxOptions[3]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
            currentlyCheckedBox = 3;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[3], "");
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxFive(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[4]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
            boxOptions[4]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
            currentlyCheckedBox = 4;
         }
      }
      else if (currentlyCheckedBox != 4)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[4]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
            boxOptions[4]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
            currentlyCheckedBox = 4;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[4], "");
      currentlyCheckedBox = -1;
   }
}

void RamWindow::updateBoxSix(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
         if ((currentAmount + itemPrices[5]) > budgetAmount)
         {
            // Logic to stop overriding the budget
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
            boxOptions[5]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
            currentlyCheckedBox = 5;
         }
      }
      else if (currentlyCheckedBox != 0)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         
         if ((currentAmount + itemPrices[5]) > budgetAmount)
         {
            QMessageBox msgBox;
            msgBox.setText("Did you look at your budget?");
            msgBox.exec();
            emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
            boxOptions[5]->setCheckState(Qt::Unchecked);
         }
         else
         {
            emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
            currentlyCheckedBox = 5;
         }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[5], "");
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
   
   images.push_back(QImage(imagesDirectory + "HighEndGSkillRam.jpeg"));
   images.push_back(QImage(imagesDirectory + "MidRangeGSkillRam.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeGskillRam.jpeg"));
   images.push_back(QImage(imagesDirectory + "HighEndCorsairRam.jpg"));
   images.push_back(QImage(imagesDirectory + "MidRangeCorsairRam.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeCorsairRam.jpeg"));
   
   for (int i = 0; i < 6; ++i)
      pixMaps.push_back(QPixmap(QPixmap::fromImage(images[i])));
}

void RamWindow::openWindowOne()
{
	specWindows[0]->setWindowTitle("Test Window 1");
	specWindows[0]->show();
	specWindows[0]->activateWindow();
}

void RamWindow::openWindowTwo()
{
	specWindows[1]->setWindowTitle("Test Window 1");
	specWindows[1]->show();
	specWindows[1]->activateWindow();
}

void RamWindow::openWindowThree()
{
	specWindows[2]->setWindowTitle("Test Window 1");
	specWindows[2]->show();
	specWindows[2]->activateWindow();
}

void RamWindow::openWindowFour()
{
	specWindows[3]->setWindowTitle("Test Window 1");
	specWindows[3]->show();
	specWindows[3]->activateWindow();
}

void RamWindow::openWindowFive()
{
	specWindows[4]->setWindowTitle("Test Window 1");
	specWindows[4]->show();
	specWindows[4]->activateWindow();
}

void RamWindow::openWindowSix()
{
	specWindows[5]->setWindowTitle("Test Window 1");
	specWindows[5]->show();
	specWindows[5]->activateWindow();
}

void RamWindow::updateCurrentAmount(double givenAmount)
{
   currentAmount = givenAmount;
}

void RamWindow::updateBudgetAmount(double givenAmount)
{
   budgetAmount = givenAmount;
}

void RamWindow::loadSpecs()
{
   specWindows[0]->addWidget(new QLabel("G.SKILL F3-2400C11Q-32GXM"));
   specWindows[0]->addWidget(new QLabel("Model"));
   specWindows[0]->addWidget(new QLabel("Brand: G.SKILL"));
   specWindows[0]->addWidget(new QLabel("Series: Ripjaws X Series"));
   specWindows[0]->addWidget(new QLabel("Details"));
   specWindows[0]->addWidget(new QLabel("Capacity: 32GB (4 x 8GB)"));
   specWindows[0]->addWidget(new QLabel("Type: 240-pin DDR3 SDRAM"));
   specWindows[0]->addWidget(new QLabel("Speed: DDR3 2400 (PC3 19200)"));
   specWindows[0]->addWidget(new QLabel("Cas Latency: 11"));
   specWindows[0]->addWidget(new QLabel("Timing: 11-13-13-31"));
   specWindows[0]->addWidget(new QLabel("Voltage: 1.65V"));
   specWindows[0]->addWidget(new QLabel("Multi-chanel Kit: Dual / Quad Channel Kit"));
   
   specWindows[1]->addWidget(new QLabel("G.SKILL F3-1600C9D-16GXM"));
   specWindows[1]->addWidget(new QLabel("Model"));
   specWindows[1]->addWidget(new QLabel("Brand: G.SKILL"));
   specWindows[1]->addWidget(new QLabel("Series: Ripjaws X Series"));
   specWindows[1]->addWidget(new QLabel("Details"));
   specWindows[1]->addWidget(new QLabel("Capacity: 16GB (2 x 8GB)"));
   specWindows[1]->addWidget(new QLabel("Type: 240-pin DDR3 SDRAM"));
   specWindows[1]->addWidget(new QLabel("Speed: DDR3 1600 (PC3 12800)"));
   specWindows[1]->addWidget(new QLabel("Cas Latency: 9"));
   specWindows[1]->addWidget(new QLabel("Timing: 9-9-9-24"));
   specWindows[1]->addWidget(new QLabel("Voltage: 1.5V"));
   specWindows[1]->addWidget(new QLabel("Multi-chanel Kit: Dual Channel Kit"));
   
   specWindows[2]->addWidget(new QLabel("G.SKILL F3-12800CL9D-8GBXL"));
   specWindows[3]->addWidget(new QLabel("Model"));
   specWindows[3]->addWidget(new QLabel("Brand: G.SKILL"));
   specWindows[3]->addWidget(new QLabel("Series: Ripjaws X Series"));
   specWindows[3]->addWidget(new QLabel("Details"));
   specWindows[3]->addWidget(new QLabel("Capacity: 8GB (2 x 4GB)"));
   specWindows[3]->addWidget(new QLabel("Type: 240-pin DDR3 SDRAM"));
   specWindows[3]->addWidget(new QLabel("Speed: DDR3 1600 (PC3 12800)"));
   specWindows[3]->addWidget(new QLabel("Cas Latency: 9"));
   specWindows[3]->addWidget(new QLabel("Timing: 9-9-9-24"));
   specWindows[3]->addWidget(new QLabel("Voltage: 1.5V"));
   specWindows[3]->addWidget(new QLabel("Multi-chanel Kit: Dual Channel Kit"));
   
   specWindows[3]->addWidget(new QLabel("Corsair CMZ32GX3M4X1866C10"));
   specWindows[3]->addWidget(new QLabel("Model"));
   specWindows[3]->addWidget(new QLabel("Brand: CORSAIR"));
   specWindows[3]->addWidget(new QLabel("Series: Vengeance"));
   specWindows[3]->addWidget(new QLabel("Details"));
   specWindows[3]->addWidget(new QLabel("Capacity: 32GB (4 x 8GB)"));
   specWindows[3]->addWidget(new QLabel("Type: 240-pin DDR3 SDRAM"));
   specWindows[3]->addWidget(new QLabel("Speed: DDR3 1866 (PC3 14900)"));
   specWindows[3]->addWidget(new QLabel("Cas Latency: 10"));
   specWindows[3]->addWidget(new QLabel("Timing: 10-11-10-30"));
   specWindows[3]->addWidget(new QLabel("Voltage: 1.5V"));
   specWindows[3]->addWidget(new QLabel("Multi-chanel Kit: Quad Channel Kit"));
   specWindows[3]->addWidget(new QLabel("Heat Spreader: Yes"));
   
   specWindows[4]->addWidget(new QLabel("Corsair CMZ16GX3M2A1600C9"));
   specWindows[4]->addWidget(new QLabel("Model"));
   specWindows[4]->addWidget(new QLabel("Brand: CORSAIR"));
   specWindows[4]->addWidget(new QLabel("Series: Vengeance"));
   specWindows[4]->addWidget(new QLabel("Details"));
   specWindows[4]->addWidget(new QLabel("Capacity: 16GB (2 x 8GB)"));
   specWindows[4]->addWidget(new QLabel("Type: 240-pin DDR3 SDRAM"));
   specWindows[4]->addWidget(new QLabel("Speed: DDR3 1600 (PC3 12800)"));
   specWindows[4]->addWidget(new QLabel("Cas Latency: 9"));
   specWindows[4]->addWidget(new QLabel("Timing: 9-9-9-24"));
   specWindows[4]->addWidget(new QLabel("Voltage: 1.5V"));
   specWindows[4]->addWidget(new QLabel("Multi-chanel Kit: Dual Channel Kit"));
   specWindows[4]->addWidget(new QLabel("Heat Spreader: Yes"));
   
   specWindows[5]->addWidget(new QLabel("Corsair CML8GX3M2A1600C9"));
   specWindows[5]->addWidget(new QLabel("Model"));
   specWindows[5]->addWidget(new QLabel("Brand: CORSAIR"));
   specWindows[5]->addWidget(new QLabel("Series: Vengeance LP"));
   specWindows[5]->addWidget(new QLabel("Details"));
   specWindows[5]->addWidget(new QLabel("Capacity: 8GB (2 x 4GB)"));
   specWindows[5]->addWidget(new QLabel("Type: 240-pin DDR3 SDRAM"));
   specWindows[5]->addWidget(new QLabel("Speed: DDR3 1600 (PC3 12800)"));
   specWindows[5]->addWidget(new QLabel("Cas Latency: 9"));
   specWindows[5]->addWidget(new QLabel("Timing: 9-9-9-24"));
   specWindows[5]->addWidget(new QLabel("Voltage: 1.5V"));
   specWindows[5]->addWidget(new QLabel("Multi-chanel Kit: Dual / Quad Channel Kit"));
   specWindows[5]->addWidget(new QLabel("Heat Spreader: Yes"));
}
