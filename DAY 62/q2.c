bool visited[1001];

// DFS function
void dfs(int** rooms, int* roomsSize, int* roomsColSize, int room) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(rooms, roomsSize, roomsColSize, key);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    // Initialize visited array
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    // Start DFS from room 0
    dfs(rooms, &roomsSize, roomsColSize, 0);

    // Check if all rooms visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}
