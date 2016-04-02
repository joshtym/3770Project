#include <QtGui>
#include "ConfirmationWindow.h"

ConfirmationWindow::ConfirmationWindow()
{
   // Variable declarations
   QHBoxLayout* mainLayout = new QHBoxLayout();
   QVBoxLayout* leftLayout = new QVBoxLayout();
   QVBoxLayout* rightLayout = new QVBoxLayout();
   
   // Variable instantiations
   budgetAmount = 0;
   currentAmount = 0;
   
   // Ensure empty vectors
   currentlySelectedObjects.clear();
   currentlySelectedObjectPrices.clear();
   
   for (int i = 0; i < 4; ++i)
   {
      currentlySelectedObjects.push_back(new QLabel("No item selected!"));
      currentlySelectedObjectPrices.push_back(new QLabel("$0"));
      leftLayout->addWidget(currentlySelectedObjects[i]);
      rightLayout->addWidget(currentlySelectedObjectPrices[i]);
   }
   
   mainLayout->addLayout(leftLayout);
   mainLayout->addLayout(rightLayout);
   this->setLayout(mainLayout);
}

ConfirmationWindow::~ConfirmationWindow()
{
}

void ConfirmationWindow::updateBudgetAmount(double givenBudget)
{
   budgetAmount = givenBudget;
}

void ConfirmationWindow::updateCurrentAmount(double givenBudget)
{
   budgetAmount = givenBudget;
}

void ConfirmationWindow::updateVectors(QString newName, double newAmount, int indexNumber)
{
   if (newName == "")
      currentlySelectedObjects[indexNumber]->setText("No item selected!");
   else
      currentlySelectedObjects[indexNumber]->setText(newName);
      
   currentlySelectedObjectPrices[indexNumber]->setText("$" + QString::number(newAmount));
}

void ConfirmationWindow::confirmPurchase()
{
   emit sendReset();
}
