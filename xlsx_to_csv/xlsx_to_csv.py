import pandas as pd
import argparse
import pathlib
import os

# Create parser and define arguments
parser = argparse.ArgumentParser(
    description="This script transfers an Excel (.xlsx) to CSV"
)
parser.add_argument("path_to_excel")
parser.add_argument("sheet_number", nargs="?", type=str)

# Parse provided arguments
args = parser.parse_args()
excel_path = str(args.path_to_excel)
sheet_number = args.sheet_number

# Process file name from provided path
file_name_ext = os.path.basename(excel_path)
file_name = os.path.splitext(file_name_ext)[0]
file_dir = os.path.dirname(excel_path)
output_dir = file_dir + "/" + file_name
pathlib.Path(output_dir).mkdir(parents=True, exist_ok=True)
# Read excel file using pandas
# sheet_number が 存在すれば、それのsheetのみ書き出す、そうでなければ全部のsheetをcsv変換する
if sheet_number:
    data = pd.read_excel(excel_path, sheet_name=sheet_number, index_col=None)
    # Write data to CSV file in the same directory as the input Excel file
    data.to_csv(
        str(output_dir) + f"/{file_name}_{sheet_number}.csv",
        index=False,
        header=False,
        encoding="utf-8",
    )
    print(str(output_dir) + f"/{file_name}_{sheet_number}.csv")
else:
    data = pd.read_excel(excel_path, sheet_name=None, index_col=None)
    for sheet_name in data.keys():
        data[sheet_name].to_csv(
            str(output_dir) + f"/{file_name}_{sheet_name}.csv",
            index=False,
            header=False,
            encoding="utf-8",
        )
        print(str(output_dir) + f"/{file_name}_{sheet_name}.csv")
