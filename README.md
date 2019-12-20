# Bracket Switcher (cbrsw)

Simple program aiming at simplyfing conversion of files to your prefered stile of writng code. Only **Linux** version.

## Usage

If installed using provided **makefile** program can be run by simply calling command cbrsw from terminal.

Runing this program without any parameters or with wrong parametrs will result in displaying help message.

The program omits brackets which are located in fields marked " or '.

Inline code:

```cpp
if(true) {cout<<"Test"; i = 10; return;}
```

remains unaffected.

### First mode

By calling the program with option **1** the following conversion will take place

Source file:

```csharp
public void SetSensor(string Name, float Left, float Right, float Top, float Bottom, float Front, float Back, bool targetEnemies){
    IMySensorBlock target = GridTerminalSystem.GetBlockWithName(Name) as IMySensorBlock;
    target.LeftExtend   = Left  ;
    target.RightExtend  = Right ;
    target.TopExtend    = Top   ;
    target.BottomExtend = Bottom;
    target.FrontExtend  = Front ;
    target.BackExtend   = Back  ;
    if(targetEnemies){
        target.DetectOwner      = false;
        target.DetectFriendly	= false;
        target.DetectEnemy      = true;
    }
    else{
        target.DetectOwner      = true;
        target.DetectFriendly	= true;
        target.DetectEnemy      = false;
    }
}
```

Output file:

```csharp
public void SetSensor(string Name, float Left, float Right, float Top, float Bottom, float Front, float Back, bool targetEnemies)
{
    IMySensorBlock target = GridTerminalSystem.GetBlockWithName(Name) as IMySensorBlock;
    target.LeftExtend   = Left  ;
    target.RightExtend  = Right ;
    target.TopExtend    = Top   ;
    target.BottomExtend = Bottom;
    target.FrontExtend  = Front ;
    target.BackExtend   = Back  ;
    if(targetEnemies)
	{
        target.DetectOwner      = false;
        target.DetectFriendly	= false;
        target.DetectEnemy      = true;
    }
    else
	{
        target.DetectOwner      = true;
        target.DetectFriendly	= true;
        target.DetectEnemy      = false;
    }
}
```

Example:

```console
cbrsw 1 file.cs
```

### Second mode

By calling the program with option **2** the following conversion will take place

Source file:

```cpp
void Bracket::loadfile()
{
    string temp;
    while(!file.eof())
    {
        getline(file, temp);
        data.push_back(temp);
    }
    file.close();
}
```

Output file:

```cpp
void Bracket::loadfile(){
    string temp;
    while(!file.eof()){
        getline(file, temp);
        data.push_back(temp);
    }
    file.close();
}
```

Example:

```console
cbrsw 2 file.cpp
```

### Overaiding source file

If we run this program on file **example.type** by default bracket switcher will write output to a new file called **example-cbrswmode.type**.
1. example - file name
1. type - file type (will be empty if source file has no type)
1. mode - which conversion was called (**1** or **2**)
1. -cbrsw - added to avoid overraidning any files unintentionally

By adding *o* to the type argument brackte switcher will override the source file.

Example:

```console
cbrsw 1o file.cpp
```

Executing this command will override the conets of file.cpp replacing them with converted code.

**WARNING** This operation is not recomended at this time and may result in data loss. Use with caution and at your own responsibility.

## Instalation

This program comes with simple "installer" 

It will copy executable of bracket switcher to:

```console
/usr/local/bin
```

which will allow it to be executed anywhere within the system. If you do not wish to do that or do not trust this program you can copy the **cbrsw** file anywhere you want and execute the program by calling:

```console
./cbrsw 
```

from the directory you copied it into.

### Instructions

1. Clone this repository to your computer by runing:

```console
git clone https://github.com/ApocalypseArisen/Bracket-switcher.git
```

2. Enter your directory by calling:

```console
cd Bracket-switcher
```

3. Run your this command and enter your password:

```console
sudo make
```

4. Done! You can now run bracket switche anywhere in your system by typing cbrsw in terminal.

### Modifiyng code

Feel free to do anything you want to do with source code of this app as long as you remember to credit me.

Source code is available in branch **code**