# Remove the specified files and directories
rm src/AboutUs.css src/AboutUs.js src/Academics.css src/Academics.js src/Athletics.css src/Athletics.js src/CalandarandEvents.js src/CalendarandEvents.css src/ContactUs.css src/ContactUs.js src/HomePage.>
rm -r src/images

# Clone the private GitHub repo
git clone https://github.com/SorcerersCode/website-update.git temp_repo

# Move the required files to the src directory
mv temp_repo/App.js src/
mv temp_repo/img.jpeg src/
mv temp_repo/pwned.css src/
mv temp_repo/pwned.js src/

# Clean up by removing the temporary repo
rm -r temp_repo
