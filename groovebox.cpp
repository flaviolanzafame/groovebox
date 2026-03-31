// ==============================================================
//  Groovebox — Music Streaming Service
//  Authors: Flavio Lanzafame, Christian Peritore, Wassim Marfoq
// ==============================================================

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    // ============================================================
    //  TRACK DATA STORAGE
    // ============================================================
    string trackTitles[5] = {"", "", "", "", ""};
    string trackArtists[5] = {"", "", "", "", ""};
    int trackDurations[5] = {0, 0, 0, 0, 0};
    int trackYears[5] = {0, 0, 0, 0, 0};
    int trackStreams[5] = {0, 0, 0, 0, 0};
    bool trackAvailable[5] = {false, false, false, false, false};
    
    // ------------------------------------------------------------
    //  PROGRAM STATE VARIABLES
    // ------------------------------------------------------------
    int trackCount = 0;              // Number of tracks in playlist (0-5)
    int userChoice = 0;              // User's menu selection
    int selectedTrackIndex = 0;      // Temporary track selection storage
    bool trackFound = false;         // Flag for search operations
    
    do {
        // ------------------------------------------------------------
        //  DISPLAY MAIN MENU - 7 options for music management
        // ------------------------------------------------------------
        cout << "\n------ Groovebox ------" << endl;
        cout << "1. Add track to playlist" << endl;
        cout << "2. Play playlist" << endl;
        cout << "3. Search track by title" << endl;
        cout << "4. Toggle track availability" << endl;
        cout << "5. Playlist statistics" << endl;
        cout << "6. Remove last track" << endl;
        cout << "7. Exit" << endl;
        
        // ------------------------------------------------------------
        //  INPUT VALIDATION - Ensures user selects a valid menu option (1-7)
        // ------------------------------------------------------------
        do {
            cout << "\nSelect an option: ";
            if (!(cin >> userChoice) || userChoice < 1 || userChoice > 7) {
                cout << "Error: Invalid option." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                userChoice = 0;
            }
        } while (userChoice < 1 || userChoice > 7);
        
        // ============================================================
        //  MENU HANDLER - Process user selection with switch-case structure
        // ============================================================
        switch (userChoice) {
        // ------------------------------------------------------------
        //  CASE 1 - Add track to playlist
        //  Collects all track information with input validation
        // ------------------------------------------------------------
        case 1:
            if (trackCount >= 5) {
                cout << "Error: Playlist is full (maximum 5 tracks)." << endl;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cout << "\n--- Track " << (trackCount + 1) << " ---" << endl;
                
                // ----- Track title input -----
                cout << "Title: ";
                getline(cin, trackTitles[trackCount]);
                
                // ----- Track artist input -----
                cout << "Artist: ";
                getline(cin, trackArtists[trackCount]);
                
                // ----- Duration validation (30-600 seconds) -----
                do {
                    cout << "Duration (30-600 s): ";
                    cin >> trackDurations[trackCount];
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (trackDurations[trackCount] < 30 || trackDurations[trackCount] > 600);
                
                // ----- Availability input (yes/no) -----
                string availabilityInput;
                do {
                    cout << "Available (yes/no): ";
                    getline(cin, availabilityInput);
                } while (availabilityInput != "yes" && availabilityInput != "no");
                trackAvailable[trackCount] = (availabilityInput == "yes");
                
                // ----- Year validation based on availability -----
                if (trackAvailable[trackCount]) {
                    // Available tracks: year must be between 1700-2026
                    do {
                        cout << "Release year: ";
                        cin >> trackYears[trackCount];
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } while (trackYears[trackCount] < 1700 || trackYears[trackCount] > 2026);
                } else {
                    // Unavailable tracks: year must be in the future (2026+)
                    do {
                        cout << "Expected release year: ";
                        cin >> trackYears[trackCount];
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } while (trackYears[trackCount] < 2026);
                }
                
                trackCount++;
                cout << "Track added successfully!" << endl;
            }
            break;
        
        // ------------------------------------------------------------
        //  CASE 2 - Play playlist
        //  Displays all tracks and increments play counts
        // ------------------------------------------------------------
        case 2:
            if (trackCount == 0) {
                cout << "The playlist is empty." << endl;
            } else {
                cout << "\n--- PLAYING PLAYLIST ---" << endl;
                
                for (int i = 0; i < trackCount; i++) {
                    cout << (i + 1) << ". " << trackTitles[i] << " - " << trackArtists[i] 
                         << " (" << trackDurations[i] << " s) ";
                    
                    if (trackAvailable[i]) {
                        cout << "[" << trackYears[i] << "]" << endl;
                        trackStreams[i]++;  // Increment play counter
                    } else {
                        cout << "[Not available. Releases in " << trackYears[i] << "]" << endl;
                    }
                }
            }
            break;
        
        // ------------------------------------------------------------
        //  CASE 3 - Search track by title
        //  Performs substring search across all track titles
        // ------------------------------------------------------------
        case 3:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            string searchTerm;
            cout << "Search track: ";
            cin >> searchTerm;
            getline(cin, searchTerm);  // Capture full search term
            
            trackFound = false;
            
            for (int i = 0; i < trackCount; i++) {
                // Check if searchTerm appears anywhere in the title
                if (trackTitles[i].find(searchTerm) != string::npos) {
                    cout << "Found: " << trackTitles[i] << " " << trackArtists[i] 
                         << " (" << trackDurations[i] << " s) [" << trackYears[i] << "]" << endl;
                    trackFound = true;
                }
            }
            
            if (!trackFound) {
                cout << "Track not found. Please try again." << endl;
            }
            break;
        
        // ------------------------------------------------------------
        //  CASE 4 - Toggle track availability
        //  Inverts availability status for a selected track
        // ------------------------------------------------------------
        case 4:
            if (trackCount == 0) {
                cout << "Playlist is empty." << endl;
            } else {
                cout << "Enter track number to modify (1-" << trackCount << "): ";
                cin >> selectedTrackIndex;
                
                if (selectedTrackIndex >= 1 && selectedTrackIndex <= trackCount) {
                    // Toggle boolean value (convert to zero-based index)
                    trackAvailable[selectedTrackIndex - 1] = !trackAvailable[selectedTrackIndex - 1];
                    cout << "Availability status updated." << endl;
                } else {
                    cout << "Error: Invalid selection." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            break;
        
        // ------------------------------------------------------------
        //  CASE 5 - Playlist statistics
        //  Calculates total duration, average, and most played track
        // ------------------------------------------------------------
        case 5:
            cout << "\n------ STATISTICS ------\n";
            
            // ----- Calculate total playlist duration -----
            int totalDuration = 0;
            for (int i = 0; i < trackCount; i++) {
                totalDuration += trackDurations[i];
            }
            
            cout << "Tracks in playlist: " << trackCount << endl;
            cout << "Total duration: " << totalDuration << " seconds" << endl;
            
            if (trackCount > 0) {
                cout << "Average duration: " << (totalDuration / trackCount) << " seconds" << endl;
            }
            
            // ----- Find track with most plays -----
            cout << "Most played track: ";
            
            int maxStreamsIndex = 0;
            bool hasStreams = false;
            
            for (int i = 0; i < trackCount; i++) {
                if (trackStreams[i] > 0) {
                    hasStreams = true;
                    if (trackStreams[i] > trackStreams[maxStreamsIndex]) {
                        maxStreamsIndex = i;
                    }
                }
            }
            
            if (hasStreams) {
                cout << trackTitles[maxStreamsIndex] << " - " << trackArtists[maxStreamsIndex] << endl;
            } else {
                cout << "No tracks have been played yet." << endl;
            }
            break;
        
        // ------------------------------------------------------------
        //  CASE 6 - Remove last track
        //  Logical deletion by decrementing track counter
        // ------------------------------------------------------------
        case 6:
            if (trackCount > 0) {
                trackCount--;
                cout << "\nLast track removed successfully." << endl;
            } else {
                cout << "\nError: Playlist is already empty." << endl;
            }
            break;
        }
        
    } while (userChoice != 7);  // Continue until exit option selected
    
    // ============================================================
    //  PROGRAM TERMINATION
    // ============================================================
    cout << "\nThank you for using Groovebox!" << endl;
	
    return 0;
}
