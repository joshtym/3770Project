#include <QtGui>
#include "PartPickerWindow.h"
#include "ProcessorWindow.h"
#include "MotherboardWindow.h"
#include "RamWindow.h"
#include "HardDriveWindow.h"

PartPickerWindow::PartPickerWindow()
{
   // Some variable declarations
   bool goodInput = false;
   QVBoxLayout* mainLayout = new QVBoxLayout();
   QHBoxLayout* budgetLayout = new QHBoxLayout();
   QWidget* centralWidget = new QWidget();
   
   // Variable instantiations
   currentSpent = new QLabel("Current Cost: $0");
   budget = new QLabel();
   budget->setAlignment(Qt::AlignLeft);
   currentSpent->setAlignment(Qt::AlignRight);
   totalAmount = 0;
   
   // Create our widgets for our parts
   infoWindow = new InfoWindow();
   cpuWindow = new ProcessorWindow();
   mbWindow = new MotherboardWindow();
   ramWindow = new RamWindow();
   hddWindow = new HardDriveWindow();
   confWindow = new ConfirmationWindow();
   
   // Instantiate our tabBar and ensure an empty vector
   tabBar = new QTabWidget();
   tabPages.clear();
   
   // Get the budget from the user
   while (!(goodInput))
   {
      // Get a budget input
      bool ok;
      budgetAmountString = QInputDialog::getText(this, tr("Budget Amount"), tr("Please enter your budget for your PC (empty for no budget):"), QLineEdit::Normal, "1000.00", &ok);
      
      if (!(ok))
      {
         close();
         break;
      }
	 
      goodInput = ok;
      
      // Check that it is indeed a good input
      if (goodInput && !(budgetAmountString.isEmpty()))
         goodInput = parseBudgetAmount(budgetAmountString);
   }
   
   // If the budget is empty, then we assume an unlimited budget. Assign the appropriate label
   if (budgetAmountString.isEmpty())
   {
      budget->setText("No budget!");
      cpuWindow->updateBudgetAmount(10000000000);
      mbWindow->updateBudgetAmount(10000000000);
      hddWindow->updateBudgetAmount(10000000000);
      ramWindow->updateBudgetAmount(10000000000);
      confWindow->updateBudgetAmount(10000000000);
      infoWindow->updateBudget(-1);
   }
   else
   {
      budget->setText("Budget: $" + budgetAmountString);
      cpuWindow->updateBudgetAmount(budgetAmount);
      mbWindow->updateBudgetAmount(budgetAmount);
      hddWindow->updateBudgetAmount(budgetAmount);
      ramWindow->updateBudgetAmount(budgetAmount);
      infoWindow->updateBudget(budgetAmount);
      confWindow->updateBudgetAmount(budgetAmount);
   }
   
   // Create some tab pages to be used
   for (int i = 0; i < 6; ++i)
      tabPages.push_back(new QScrollArea());
   
   // Set the scroll area widgets
   tabPages[0]->setWidget(infoWindow);
   tabPages[1]->setWidget(cpuWindow);
   tabPages[2]->setWidget(mbWindow);
   tabPages[3]->setWidget(ramWindow);
   tabPages[4]->setWidget(hddWindow);
   tabPages[5]->setWidget(confWindow);
   
   // Ensure resizability
   tabPages[0]->setWidgetResizable(true);
   tabPages[1]->setWidgetResizable(true);
   tabPages[2]->setWidgetResizable(true);
   tabPages[3]->setWidgetResizable(true);
   tabPages[4]->setWidgetResizable(true);
   tabPages[5]->setWidgetResizable(true);
   
   // Let's name those tabs and add the scroll areas
   tabBar->addTab(tabPages[0], "Information");
   tabBar->addTab(tabPages[1], "CPU");
   tabBar->addTab(tabPages[2], "Motherboard");
   tabBar->addTab(tabPages[3], "RAM");
   tabBar->addTab(tabPages[4], "HDD");
   tabBar->addTab(tabPages[5], "Confirmation");
   
   // Set the layouts
   budgetLayout->addWidget(budget);
   budgetLayout->addWidget(currentSpent);
   mainLayout->addWidget(tabBar);
   mainLayout->addLayout(budgetLayout);
   
   // Set this to be the central widget and assign our layout
   setCentralWidget(centralWidget);
   centralWidget->setLayout(mainLayout);
   
   // Create connectors to update costs
   connect(cpuWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(mbWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(ramWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(hddWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(infoWindow, SIGNAL(budgetUpdated(double)), this, SLOT(budgetUpdated(double)));
   connect(confWindow, SIGNAL(sendReset()), this, SLOT(resetSelection()));
}

void PartPickerWindow::receiveAmountUpdate(double newAmount, double oldAmount, QString deviceName)
{
   // Update the total amount and set the current cost
   totalAmount = totalAmount + newAmount - oldAmount;
   
   // Ensure no weirdness with odd math
   if (totalAmount < 0.0001)
   {
      totalAmount = 0;
      currentSpent->setText("Current Cost: $0");
   }
   else
      currentSpent->setText("Current Cost: $" + QString::number(totalAmount));
   
   // Update each widget with the totalAmount
   cpuWindow->updateCurrentAmount(totalAmount);
   mbWindow->updateCurrentAmount(totalAmount);
   hddWindow->updateCurrentAmount(totalAmount);
   ramWindow->updateCurrentAmount(totalAmount);
   confWindow->updateCurrentAmount(totalAmount);

   // Update vectors in our confirmation window
   confWindow->updateVectors(deviceName, newAmount, tabBar->currentIndex() - 1);
   
   // Let's ensure proper enablement / disablement of options in
   // the mobo or CPU
   if (newAmount == 0)
      adjustAvailableOptions(deviceName, false);
   else
      adjustAvailableOptions(deviceName, true);
}


void PartPickerWindow::budgetUpdated(double budgetInput)
{
   // Set the new budgetAmount and reset all our values
   budgetAmount = budgetInput;
   resetSelection();
   
   if (budgetInput != -1)
   {
      // Update out text
      budgetAmountString = QString::number(budgetAmount);
      budget->setText("Budget: $" + budgetAmountString);
      
      // Update each widget
      cpuWindow->updateBudgetAmount(budgetAmount);
      mbWindow->updateBudgetAmount(budgetAmount);
      hddWindow->updateBudgetAmount(budgetAmount);
      ramWindow->updateBudgetAmount(budgetAmount);
      infoWindow->updateBudget(budgetAmount);
      confWindow->updateBudgetAmount(budgetAmount);
   }
   else
   {
      // Update our text
      budget->setText("No budget!");
      
      // Update each widget
      cpuWindow->updateBudgetAmount(10000000000);
      mbWindow->updateBudgetAmount(10000000000);
      hddWindow->updateBudgetAmount(10000000000);
      ramWindow->updateBudgetAmount(10000000000);
      confWindow->updateBudgetAmount(10000000000);
      infoWindow->updateBudget(-1);
   }
} 

void PartPickerWindow::resetSelection()
{
   // Reset each widget
   cpuWindow->resetSelection();
   mbWindow->resetSelection();
   hddWindow->resetSelection();
   ramWindow->resetSelection();
}

bool PartPickerWindow::parseBudgetAmount(QString budgetString)
{
   // Try to parse the budget amount
   bool success = false;
   budgetAmount = budgetString.toDouble(&success);
   
   if (budgetAmount < 0)
      success = false;
      
   return success;
}

void PartPickerWindow::adjustAvailableOptions(QString deviceName, bool disable)
{
   // Logic to update the MOBO and CPU available options
   if (deviceName.contains("AMD") && (!(deviceName.contains("Motherboard"))))
      mbWindow->updateAvailableOptions("AMD", disable);
   else if ((deviceName.contains("Intel")) && (!(deviceName.contains("Motherboard"))))
      mbWindow->updateAvailableOptions("Intel", disable);
   else if (deviceName.contains("AMD"))
      cpuWindow->updateAvailableOptions("AMD", disable);
   else if (deviceName.contains("Intel"))
      cpuWindow->updateAvailableOptions("Intel", disable);
}
