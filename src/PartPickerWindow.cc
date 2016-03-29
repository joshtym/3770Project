#include <QtGui>
#include "PartPickerWindow.h"

PartPickerWindow::PartPickerWindow()
{
   // Some variable declarations
   bool goodInput, noBudget = false;
   QString budgetAmountString;
   
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
   
   // If the budget is empty, then we assume an unlimited budget
   if (budgetAmountString.isEmpty())
      noBudget = true;
   
   // Create some tab pages to be used
   for (int i = 0; i < 4; ++i)
      tabPages.push_back(new QScrollArea());
   
   // Create our widgets for our parts
   cpuWindow = new ProcessorWindow();
   mbWindow = new MotherboardWindow();
   
   // Set the scroll area widgets
   tabPages[0]->setWidget(new ProcessorWindow());
   tabPages[1]->setWidget(new MotherboardWindow());
   
   // Ensure resizability
   tabPages[0]->setWidgetResizable(true);
   tabPages[1]->setWidgetResizable(true);
   
   // Let's name those tabs and add the scroll areas
   tabBar->addTab(tabPages[0], "CPU");
   tabBar->addTab(tabPages[1], "Motherboard");
   
   // Set this to be the central widget
   setCentralWidget(tabBar);
}

bool PartPickerWindow::parseBudgetAmount(QString budgetString)
{
   bool success = false;
   budgetAmount = budgetString.toDouble(&success);
   return success;
}
