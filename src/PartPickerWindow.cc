#include <QtGui>
#include "PartPickerWindow.h"

PartPickerWindow::PartPickerWindow()
{
   // Some variable declarations
   bool goodInput = false;
   QString budgetAmountString;
   QVBoxLayout* mainLayout = new QVBoxLayout();
   QHBoxLayout* budgetLayout = new QHBoxLayout();
   QWidget* centralWidget = new QWidget();
   QLabel* budget = new QLabel();
   
   // Variable instantiations
   currentSpent = new QLabel("Current Cost: $0");
   budget->setAlignment(Qt::AlignLeft);
   currentSpent->setAlignment(Qt::AlignRight);
   totalAmount = 0;
   productSelectionNames.clear();
   productSelectionPrices.clear();
   
   // Load up them guns
   for (int i = 0; i < 4; ++i)
   {
      productSelectionNames.push_back("");
      productSelectionPrices.push_back(0);
   }
   
   // Instantiate our tabBar and ensure an empty vector
   tabBar = new QTabWidget();
   tabPages.clear();
   
   // Get the budget from the user
   while (!(goodInput))
   {
      budgetAmountString = QInputDialog::getText(this, tr("Budget Amount"), tr("Please enter your budget for your PC (empty for no budget):"), QLineEdit::Normal, "1000.00", &goodInput);
      
      // Check that it is indeed a good input
      if (goodInput && !(budgetAmountString.isEmpty()))
         goodInput = parseBudgetAmount(budgetAmountString);
   }
   
   // If the budget is empty, then we assume an unlimited budget. Assign the appropriate label
   if (budgetAmountString.isEmpty())
      budget->setText("No budget!");
   else
      budget->setText("Budget: $" + budgetAmountString);
   
   // Create some tab pages to be used
   for (int i = 0; i < 5; ++i)
      tabPages.push_back(new QScrollArea());
   
   // Create our widgets for our parts
   infoWindow = new InfoTab();
   cpuWindow = new ProcessorWindow();
   mbWindow = new MotherboardWindow();
   ramWindow = new RamWindow();
   hddWindow = new HardDriveWindow();
   
   // Set the scroll area widgets
   tabPages[0]->setWidget(infoWindow);
   tabPages[1]->setWidget(cpuWindow);
   tabPages[2]->setWidget(mbWindow);
   tabPages[3]->setWidget(ramWindow);
   tabPages[4]->setWidget(hddWindow);
   
   // Ensure resizability
   tabPages[0]->setWidgetResizable(true);
   tabPages[1]->setWidgetResizable(true);
   tabPages[2]->setWidgetResizable(true);
   tabPages[3]->setWidgetResizable(true);
   tabPages[4]->setWidgetResizable(true);
   
   // Let's name those tabs and add the scroll areas
   tabBar->addTab(tabPages[0], "Information");
   tabBar->addTab(tabPages[1], "CPU");
   tabBar->addTab(tabPages[2], "Motherboard");
   tabBar->addTab(tabPages[3], "RAM");
   tabBar->addTab(tabPages[4], "HDD");
   
   // Set the layouts
   budgetLayout->addWidget(budget);
   budgetLayout->addWidget(currentSpent);
   mainLayout->addWidget(tabBar);
   mainLayout->addLayout(budgetLayout);
   
   // Set this to be the central widget and assign our layout
   setCentralWidget(centralWidget);
   centralWidget->setLayout(mainLayout);
   
   connect(cpuWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(mbWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(ramWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(hddWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
}

bool PartPickerWindow::parseBudgetAmount(QString budgetString)
{
   bool success = false;
   budgetAmount = budgetString.toDouble(&success);
   return success;
}

void PartPickerWindow::receiveAmountUpdate(double newAmount, double oldAmount, QString deviceName)
{
   totalAmount = totalAmount + newAmount - oldAmount;
   currentSpent->setText("Current Cost: $" + QString::number(totalAmount));
   
   if (newAmount != 0 && oldAmount == 0)
   {
      productSelectionNames[tabBar->currentIndex() - 1] = deviceName;
      productSelectionPrices[tabBar->currentIndex() - 1] = newAmount;
   }
}
