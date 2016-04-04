#ifndef HARDDRIVEWINDOW_H
#define HARDDRIVEWINDOW_H

#include "PartPageInterface.h"

class HardDriveWindow : public PartPageInterface
{
   public:
      // Constructor
      HardDriveWindow();
      
      // Destructor
      ~HardDriveWindow();
   
   protected:
      // Instantiated virtual function to initialize our vector values
      virtual void initVectorValues();
      
      // Instantiated virtual function to update info for spec windows
      virtual void loadSpecs();
      
      // Instantiated virtual function to load our iamges
      virtual void loadAssets();
};
#endif
