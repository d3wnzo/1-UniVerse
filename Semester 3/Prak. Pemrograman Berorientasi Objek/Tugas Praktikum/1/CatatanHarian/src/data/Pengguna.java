package data;

public class Pengguna {
    private String username;
    private String password;

    public Pengguna() {
        this.username = "";
        this.password = "";
    }

    public Pengguna(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}