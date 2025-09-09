# PowerShell script to automatically move .exe files to output folder

# Create output folder if it doesn't exist
if (!(Test-Path "output")) {
    New-Item -ItemType Directory -Name "output"
    Write-Host "Created output folder" -ForegroundColor Green
}

# Get all .exe files in current directory
$exeFiles = Get-ChildItem -Filter "*.exe"

if ($exeFiles.Count -eq 0) {
    Write-Host "No .exe files found in current directory" -ForegroundColor Yellow
} else {
    # Move each .exe file to output folder
    foreach ($file in $exeFiles) {
        Write-Host "Moving $($file.Name) to output folder..." -ForegroundColor Cyan
        Move-Item $file.FullName "output\"
    }
    Write-Host "All $($exeFiles.Count) .exe files moved to output folder!" -ForegroundColor Green
}
