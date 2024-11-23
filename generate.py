import os

def generate_readme(root_dir, readme_path):
    with open(readme_path, 'w') as readme_file:
        readme_file.write("# Repository Index\n\n")
        
        for root, dirs, files in os.walk(root_dir):
            level = root.replace(root_dir, '').count(os.sep)
            indent = ' ' * 4 * level
            dir_name = os.path.basename(root)
            if dir_name:
                readme_file.write(f"{indent}- [{dir_name}]({root.replace(' ', '%20')}/)\n")
            subindent = ' ' * 4 * (level + 1)
            for f in files:
                file_path = os.path.join(root, f).replace(' ', '%20')
                readme_file.write(f"{subindent}- [{f}]({file_path})\n")

if __name__ == "__main__":
    root_directory = '.'  # Change this to your repository root directory
    readme_file_path = 'README.md'
    generate_readme(root_directory, readme_file_path)