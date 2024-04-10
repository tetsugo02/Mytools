import pandas as pd
import argparse
import os

# Create parser and define arguments
parser = argparse.ArgumentParser(
    description="This script transfers an Excel (.xlsx) to CSV"
)
parser.add_argument("path_to_excel")
parser.add_argument("--sheet_number", default="Sheet1")

# Parse provided arguments
args = parser.parse_args()
excel_path = str(args.path_to_excel)
sheet_number = str(args.sheet_number)

# Process file name from provided path
file_name_ext = os.path.basename(excel_path)
file_name = os.path.splitext(file_name_ext)[0]
output_dir = os.path.dirname(excel_path)

# Read excel file using pandas
data = pd.read_excel(excel_path, sheet_name=sheet_number, index_col=None)

# Write data to CSV file in the same directory as the input Excel file
data.to_csv(
    os.path.join(output_dir, file_name + ".csv"),
    index=False,
    header=False,
    encoding="utf-8",
)
