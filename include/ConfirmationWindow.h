#ifndef CONFIRMATIONWINDOW_H
#define CONFIRMATIONWINDOW_H

#include <QWidget>
#include <vector>

// Forward Declarations
class QString;
class QLabel;

class ConfirmationWindow : public QWidget
{
   // Meta object compiler
   Q_OBJECT
   
   public:
      // Default constructor
      ConfirmationWindow();
      
      // Destructor of class
      ~ConfirmationWindow();
      
      // Public function to update budget amount
      void updateBudgetAmount(double);
      
      // Public function to update our current amount
      void updateCurrentAmount(double);
      
      // Public function to update our vectors
      void updateVectors(QString, double, int);
      
   signals:
      void sendReset();
      
   private slots:
      // Slot to confirm the purchase
      void confirmPurchase();
      
   private:
      // Helper function to reset all values
      void resetValues();
      
      std::vector<QLabel*> currentlySelectedObjects;
      std::vector<QLabel*> currentlySelectedObjectPrices;
      QLabel* budgetLabel;
      QLabel* amountLabel;
      double currentAmount;
      double budgetAmount;
};
#endif
