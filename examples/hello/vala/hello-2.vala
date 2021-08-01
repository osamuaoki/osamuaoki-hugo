using GLib;
public class Demo.HelloWorld : GLib.Object {
    public int hello() {
        stdout.printf("Hello, world!\n");
        return 0;
    }
}

int main(string[] args) {
    var obj = new Demo.HelloWorld();
    obj.hello();
    return 0;
}
