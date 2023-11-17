module sinegen #(
    parameter A_WIDTH = 8,
              D_WIDTH = 8
)(
    // interface signals
    input logic                clk, // clock
    input logic                rst, // reset
    input logic                en, // enable
    input logic [D_WIDTH-1:0]  incr, // increment for addr counter
    input logic [D_WIDTH-1:0]  offset,
    output logic [D_WIDTH-1:0] dout1, // output data
    output logic [D_WIDTH-1:0] dout2
);
    logic [A_WIDTH-1:0]        address1;  //interconnect wire
    logic [A_WIDTH-1:0]        address2;

counter addrCounter (
    .clk (clk),
    .rst (rst),
    .en (en),
    .offset (offset),
    .incr (incr),
    .count1 (address1),
    .count2 (address2)
);

dualrom sineRom (
    .clk (clk),
    .addr1 (address1),
    .addr2 (address2),
    .dout1 (dout1),
    .dout2 (dout2)
);

endmodule
