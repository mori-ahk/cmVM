# cmVM
A virtual machine that can be ported on small-footprint embedded systems

## How to compile
This project was built and compile with Clion IDE on macOS.
The project includes `CMakeLists` file which can be built using `cmake` command.
#### Build Flag (Cmake options)
##### macOS
This flag should be passed if the project in being compiled on macOS, otherwise `BAD_ACCESS` exception would be thrown. The defualt configuration of the VM uses 32-bit variable to store the 64-bit base address in `GetBaseAddr` function which causes an overflow, therefore an exception is thrown. `macOS` build flag ensures that those variables are 64-bit to avoid that issue.

## File structures
    ├── src
    │   ├── BSL                 # BSL layer classes and header files
    │   ├── HAL                 # HAL layer classes and header files
    │   ├── VM Core             # Core functionalities of VM
    │   ├── VM stack            # VM operand stack
    │   ├── Suite_of_12_Tests   # List of precompiled tests
    │   ├── Task5 - Tests       # List of small tests for task 5
    │   ├── Tests               # .c tests classes provided by the professor for task 3, 6 and 7
    │   └── Util                # Includes shell scripts plus aunit and serial loader executables
    ├── README.md
    └── CMakeLists.txt

## How to test
There is a shell script for each task which does the following:
1.  Compile the necessary files for that task using `avr-gcc`
2.  Load the `.hex` file to the target (Arduino Nano)

### Usage
All the scripts except `task1.sh` expects an argument, which is the serial port that the target (Arduino Nano) is connected to. 
> For example: bash task6.sh /dev/cu.usbserial14110

After compiling the files and loading the `.hex` file to the target (Arduino Nano) successfully, you can have the serial communication to see the output using the `screen` command. And if you would like to have the result in a log file, pass `-L` flag to `screen`.

> **Screen command is only available in Linux and macOS**
> For example: screen -L /dev/cu.usbserial14110

#### More about task 1
After running `task1.sh`, the `VMOutput.txt` will be generated in the same directory with all the test cases output.

#### More about task 5
The `SerialLoader.cs` was built using `mono`. Although the executable is included in the project, in case it needs to be rebuilt, here is how to do it:
1. run `brew install mono` (if not already installed)
2. head to the `SerialLoader.cs` directory
3. run `mcs -d:LoadFromFile SerialLoader.cs`
4. run `mono SerialLoader.exe PATH_TO_TEST`
