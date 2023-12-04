
#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -lt 1 ]; then
  echo "Usage: $0 <directory1> [<directory2> ...]"
  exit 1
fi

# Create the backups directory if it does not exist
backup_dir="backups"
mkdir -p "$backup_dir"

# Loop through each provided directory
for dir in "$@"; do
  # Check if the directory exists
  if [ ! -d "$dir" ]; then
    echo "Error: $dir is not a valid directory. Skipping."
    continue
  fi

  # Extract the directory name from the path
  dir_name=$(basename "$dir")

  # Create a backup filename with the current date
  backup_filename="backup_${dir_name}_$(date +'%Y%m%d_%H%M%S').tar.gz"

  # Perform the backup and display appropriate messages
  tar -czf "$backup_dir/$backup_filename" "$dir" && \
    echo "Backup of $dir successful: $backup_filename" || \
    echo "Backup of $dir failed"
done

echo "Backup process completed."
