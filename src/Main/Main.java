package Main;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Main {
    public static void main(String[] args) throws SQLException {
        DB db = new DB();
        Connection app = db.connect();
        Statement stmt = app.createStatement();
        ResultSet rs = stmt.executeQuery( "SELECT * FROM Test" );
        while(rs.next()){
            String name = rs.getString("name");
            String id = rs.getString("id");
            System.out.println(name+" "+id);
        }
    }}
