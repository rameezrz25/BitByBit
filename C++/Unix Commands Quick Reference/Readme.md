# 🐧 **Unix Commands Quick Reference** 📜

This is a handy guide for common Unix commands and their uses.  

---

## 🕒 **Basic Commands**

- **`date`**: Displays the current date and time.  
- **`cal`**: Shows the current month’s calendar.  
- **`cal 1 2024`**: Displays the calendar for **January 2024**.  
- **`cal -y`**: Shows the calendar for the entire current year.  

---

## 📂 **Directory Navigation**

- **`pwd`**: Prints the current working directory.  
- **`ls`**: Lists files and directories in the current directory.  
- **`cd`**: Changes the current directory.  
  - **`cd ~`**: Moves to the **home directory**.  
  - **`cd /`**: Moves to the **root directory**.  
  - **`cd -`**: Switches back to the **previous directory**.  
- **`ls ~`**: Lists files in the **home directory**.  

---

## 📁 **Specific Directory Listings**

- **`ls anaconda/ssl`**: Lists files in the `anaconda/ssl` directory.  

---

## 🔗 **Links and File Information**

- **Hard Link**: Directly references the **data of an existing file**.  
  - Created using: `ln`  
- **Soft Link (Symbolic Link)**: Points to another file’s **path**.  
  - Created using: `ln -s`  

### File Information Commands:
- **`ls -i`**: Lists files with their **inode numbers**.  
- **`ls -l`**: Lists files in **long format**, showing:  
  - Permissions  
  - Owner  
  - Size  
  - Modification date  

---

## 🛠️ **Linking Files**

- **`ln f1 f2`**: Creates a **hard link** from `f1` to `f2`.  
- **`ln -s f1 f2`**: Creates a **symbolic (soft) link** from `f1` to `f2`.  

---

## 🎯 **Quick Tips**  
- Use **`man <command>`** for detailed command documentation.  
- Use **`--help`** with commands for quick syntax guidance.  

---

Happy exploring the Unix world! 🚀  
