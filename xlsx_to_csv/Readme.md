# Environment
    source ~/venv/bin/activate
Make sure you have the following packages installed:
```bash
pip install pandas
pip install openpyxl
```
# Usage
```bash
python3 xlsx_to_csv.py path/to/file.xlsx SheetName (default: None)
```
If you do not specify the sheet name, the script will convert all sheets to csv files. The new csv files will be saved in the directory which has a same name as the xlsx file in the same directory as the xlsx file.
# Example
```bash
python3 xlsx_to_csv.py code/test.xlsx Sheet1
```
the above command will creat a csv file in the directory as ``code/test/test_Sheet1.csv``.
