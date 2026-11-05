/*
 * ESPBoOm8266TX 0.2.0 — standalone sketch.
 * All project code, Wi-Fi configuration and gzip HTML are integrated below.
 * Uses only the libraries bundled with Arduino ESP8266 core 3.1.2.
 * D1 mini, 160 MHz, 4 MB flash / 1 MB filesystem, default SDK and MMU, ip=hb2f.
 * HTTP port 80, WebSocket port 81 (/ws). No automatic RF transmission at boot.
 * PRIVATE CONFIGURED COPY: keep the integrated Wi-Fi configuration private.
 */
#include <Arduino.h>
#if !defined(NONOSDK22x_190703)
#error "This tested RF-session build requires the default D1 mini SDK22x_190703"
#endif
void setup();
void loop();

/* ===== Embedded WebSocket license: COPYING.LESSER =====
                  GNU LESSER GENERAL PUBLIC LICENSE
                       Version 2.1, February 1999

 Copyright (C) 1991, 1999 Free Software Foundation, Inc.
 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.

[This is the first released version of the Lesser GPL.  It also counts
 as the successor of the GNU Library Public License, version 2, hence
 the version number 2.1.]

                            Preamble

  The licenses for most software are designed to take away your
freedom to share and change it.  By contrast, the GNU General Public
Licenses are intended to guarantee your freedom to share and change
free software--to make sure the software is free for all its users.

  This license, the Lesser General Public License, applies to some
specially designated software packages--typically libraries--of the
Free Software Foundation and other authors who decide to use it.  You
can use it too, but we suggest you first think carefully about whether
this license or the ordinary General Public License is the better
strategy to use in any particular case, based on the explanations below.

  When we speak of free software, we are referring to freedom of use,
not price.  Our General Public Licenses are designed to make sure that
you have the freedom to distribute copies of free software (and charge
for this service if you wish); that you receive source code or can get
it if you want it; that you can change the software and use pieces of
it in new free programs; and that you are informed that you can do
these things.

  To protect your rights, we need to make restrictions that forbid
distributors to deny you these rights or to ask you to surrender these
rights.  These restrictions translate to certain responsibilities for
you if you distribute copies of the library or if you modify it.

  For example, if you distribute copies of the library, whether gratis
or for a fee, you must give the recipients all the rights that we gave
you.  You must make sure that they, too, receive or can get the source
code.  If you link other code with the library, you must provide
complete object files to the recipients, so that they can relink them
with the library after making changes to the library and recompiling
it.  And you must show them these terms so they know their rights.

  We protect your rights with a two-step method: (1) we copyright the
library, and (2) we offer you this license, which gives you legal
permission to copy, distribute and/or modify the library.

  To protect each distributor, we want to make it very clear that
there is no warranty for the free library.  Also, if the library is
modified by someone else and passed on, the recipients should know
that what they have is not the original version, so that the original
author's reputation will not be affected by problems that might be
introduced by others.

  Finally, software patents pose a constant threat to the existence of
any free program.  We wish to make sure that a company cannot
effectively restrict the users of a free program by obtaining a
restrictive license from a patent holder.  Therefore, we insist that
any patent license obtained for a version of the library must be
consistent with the full freedom of use specified in this license.

  Most GNU software, including some libraries, is covered by the
ordinary GNU General Public License.  This license, the GNU Lesser
General Public License, applies to certain designated libraries, and
is quite different from the ordinary General Public License.  We use
this license for certain libraries in order to permit linking those
libraries into non-free programs.

  When a program is linked with a library, whether statically or using
a shared library, the combination of the two is legally speaking a
combined work, a derivative of the original library.  The ordinary
General Public License therefore permits such linking only if the
entire combination fits its criteria of freedom.  The Lesser General
Public License permits more lax criteria for linking other code with
the library.

  We call this license the "Lesser" General Public License because it
does Less to protect the user's freedom than the ordinary General
Public License.  It also provides other free software developers Less
of an advantage over competing non-free programs.  These disadvantages
are the reason we use the ordinary General Public License for many
libraries.  However, the Lesser license provides advantages in certain
special circumstances.

  For example, on rare occasions, there may be a special need to
encourage the widest possible use of a certain library, so that it becomes
a de-facto standard.  To achieve this, non-free programs must be
allowed to use the library.  A more frequent case is that a free
library does the same job as widely used non-free libraries.  In this
case, there is little to gain by limiting the free library to free
software only, so we use the Lesser General Public License.

  In other cases, permission to use a particular library in non-free
programs enables a greater number of people to use a large body of
free software.  For example, permission to use the GNU C Library in
non-free programs enables many more people to use the whole GNU
operating system, as well as its variant, the GNU/Linux operating
system.

  Although the Lesser General Public License is Less protective of the
users' freedom, it does ensure that the user of a program that is
linked with the Library has the freedom and the wherewithal to run
that program using a modified version of the Library.

  The precise terms and conditions for copying, distribution and
modification follow.  Pay close attention to the difference between a
"work based on the library" and a "work that uses the library".  The
former contains code derived from the library, whereas the latter must
be combined with the library in order to run.

                  GNU LESSER GENERAL PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. This License Agreement applies to any software library or other
program which contains a notice placed by the copyright holder or
other authorized party saying it may be distributed under the terms of
this Lesser General Public License (also called "this License").
Each licensee is addressed as "you".

  A "library" means a collection of software functions and/or data
prepared so as to be conveniently linked with application programs
(which use some of those functions and data) to form executables.

  The "Library", below, refers to any such software library or work
which has been distributed under these terms.  A "work based on the
Library" means either the Library or any derivative work under
copyright law: that is to say, a work containing the Library or a
portion of it, either verbatim or with modifications and/or translated
straightforwardly into another language.  (Hereinafter, translation is
included without limitation in the term "modification".)

  "Source code" for a work means the preferred form of the work for
making modifications to it.  For a library, complete source code means
all the source code for all modules it contains, plus any associated
interface definition files, plus the scripts used to control compilation
and installation of the library.

  Activities other than copying, distribution and modification are not
covered by this License; they are outside its scope.  The act of
running a program using the Library is not restricted, and output from
such a program is covered only if its contents constitute a work based
on the Library (independent of the use of the Library in a tool for
writing it).  Whether that is true depends on what the Library does
and what the program that uses the Library does.

  1. You may copy and distribute verbatim copies of the Library's
complete source code as you receive it, in any medium, provided that
you conspicuously and appropriately publish on each copy an
appropriate copyright notice and disclaimer of warranty; keep intact
all the notices that refer to this License and to the absence of any
warranty; and distribute a copy of this License along with the
Library.

  You may charge a fee for the physical act of transferring a copy,
and you may at your option offer warranty protection in exchange for a
fee.

  2. You may modify your copy or copies of the Library or any portion
of it, thus forming a work based on the Library, and copy and
distribute such modifications or work under the terms of Section 1
above, provided that you also meet all of these conditions:

    a) The modified work must itself be a software library.

    b) You must cause the files modified to carry prominent notices
    stating that you changed the files and the date of any change.

    c) You must cause the whole of the work to be licensed at no
    charge to all third parties under the terms of this License.

    d) If a facility in the modified Library refers to a function or a
    table of data to be supplied by an application program that uses
    the facility, other than as an argument passed when the facility
    is invoked, then you must make a good faith effort to ensure that,
    in the event an application does not supply such function or
    table, the facility still operates, and performs whatever part of
    its purpose remains meaningful.

    (For example, a function in a library to compute square roots has
    a purpose that is entirely well-defined independent of the
    application.  Therefore, Subsection 2d requires that any
    application-supplied function or table used by this function must
    be optional: if the application does not supply it, the square
    root function must still compute square roots.)

These requirements apply to the modified work as a whole.  If
identifiable sections of that work are not derived from the Library,
and can be reasonably considered independent and separate works in
themselves, then this License, and its terms, do not apply to those
sections when you distribute them as separate works.  But when you
distribute the same sections as part of a whole which is a work based
on the Library, the distribution of the whole must be on the terms of
this License, whose permissions for other licensees extend to the
entire whole, and thus to each and every part regardless of who wrote
it.

Thus, it is not the intent of this section to claim rights or contest
your rights to work written entirely by you; rather, the intent is to
exercise the right to control the distribution of derivative or
collective works based on the Library.

In addition, mere aggregation of another work not based on the Library
with the Library (or with a work based on the Library) on a volume of
a storage or distribution medium does not bring the other work under
the scope of this License.

  3. You may opt to apply the terms of the ordinary GNU General Public
License instead of this License to a given copy of the Library.  To do
this, you must alter all the notices that refer to this License, so
that they refer to the ordinary GNU General Public License, version 2,
instead of to this License.  (If a newer version than version 2 of the
ordinary GNU General Public License has appeared, then you can specify
that version instead if you wish.)  Do not make any other change in
these notices.

  Once this change is made in a given copy, it is irreversible for
that copy, so the ordinary GNU General Public License applies to all
subsequent copies and derivative works made from that copy.

  This option is useful when you wish to copy part of the code of
the Library into a program that is not a library.

  4. You may copy and distribute the Library (or a portion or
derivative of it, under Section 2) in object code or executable form
under the terms of Sections 1 and 2 above provided that you accompany
it with the complete corresponding machine-readable source code, which
must be distributed under the terms of Sections 1 and 2 above on a
medium customarily used for software interchange.

  If distribution of object code is made by offering access to copy
from a designated place, then offering equivalent access to copy the
source code from the same place satisfies the requirement to
distribute the source code, even though third parties are not
compelled to copy the source along with the object code.

  5. A program that contains no derivative of any portion of the
Library, but is designed to work with the Library by being compiled or
linked with it, is called a "work that uses the Library".  Such a
work, in isolation, is not a derivative work of the Library, and
therefore falls outside the scope of this License.

  However, linking a "work that uses the Library" with the Library
creates an executable that is a derivative of the Library (because it
contains portions of the Library), rather than a "work that uses the
library".  The executable is therefore covered by this License.
Section 6 states terms for distribution of such executables.

  When a "work that uses the Library" uses material from a header file
that is part of the Library, the object code for the work may be a
derivative work of the Library even though the source code is not.
Whether this is true is especially significant if the work can be
linked without the Library, or if the work is itself a library.  The
threshold for this to be true is not precisely defined by law.

  If such an object file uses only numerical parameters, data
structure layouts and accessors, and small macros and small inline
functions (ten lines or less in length), then the use of the object
file is unrestricted, regardless of whether it is legally a derivative
work.  (Executables containing this object code plus portions of the
Library will still fall under Section 6.)

  Otherwise, if the work is a derivative of the Library, you may
distribute the object code for the work under the terms of Section 6.
Any executables containing that work also fall under Section 6,
whether or not they are linked directly with the Library itself.

  6. As an exception to the Sections above, you may also combine or
link a "work that uses the Library" with the Library to produce a
work containing portions of the Library, and distribute that work
under terms of your choice, provided that the terms permit
modification of the work for the customer's own use and reverse
engineering for debugging such modifications.

  You must give prominent notice with each copy of the work that the
Library is used in it and that the Library and its use are covered by
this License.  You must supply a copy of this License.  If the work
during execution displays copyright notices, you must include the
copyright notice for the Library among them, as well as a reference
directing the user to the copy of this License.  Also, you must do one
of these things:

    a) Accompany the work with the complete corresponding
    machine-readable source code for the Library including whatever
    changes were used in the work (which must be distributed under
    Sections 1 and 2 above); and, if the work is an executable linked
    with the Library, with the complete machine-readable "work that
    uses the Library", as object code and/or source code, so that the
    user can modify the Library and then relink to produce a modified
    executable containing the modified Library.  (It is understood
    that the user who changes the contents of definitions files in the
    Library will not necessarily be able to recompile the application
    to use the modified definitions.)

    b) Use a suitable shared library mechanism for linking with the
    Library.  A suitable mechanism is one that (1) uses at run time a
    copy of the library already present on the user's computer system,
    rather than copying library functions into the executable, and (2)
    will operate properly with a modified version of the library, if
    the user installs one, as long as the modified version is
    interface-compatible with the version that the work was made with.

    c) Accompany the work with a written offer, valid for at
    least three years, to give the same user the materials
    specified in Subsection 6a, above, for a charge no more
    than the cost of performing this distribution.

    d) If distribution of the work is made by offering access to copy
    from a designated place, offer equivalent access to copy the above
    specified materials from the same place.

    e) Verify that the user has already received a copy of these
    materials or that you have already sent this user a copy.

  For an executable, the required form of the "work that uses the
Library" must include any data and utility programs needed for
reproducing the executable from it.  However, as a special exception,
the materials to be distributed need not include anything that is
normally distributed (in either source or binary form) with the major
components (compiler, kernel, and so on) of the operating system on
which the executable runs, unless that component itself accompanies
the executable.

  It may happen that this requirement contradicts the license
restrictions of other proprietary libraries that do not normally
accompany the operating system.  Such a contradiction means you cannot
use both them and the Library together in an executable that you
distribute.

  7. You may place library facilities that are a work based on the
Library side-by-side in a single library together with other library
facilities not covered by this License, and distribute such a combined
library, provided that the separate distribution of the work based on
the Library and of the other library facilities is otherwise
permitted, and provided that you do these two things:

    a) Accompany the combined library with a copy of the same work
    based on the Library, uncombined with any other library
    facilities.  This must be distributed under the terms of the
    Sections above.

    b) Give prominent notice with the combined library of the fact
    that part of it is a work based on the Library, and explaining
    where to find the accompanying uncombined form of the same work.

  8. You may not copy, modify, sublicense, link with, or distribute
the Library except as expressly provided under this License.  Any
attempt otherwise to copy, modify, sublicense, link with, or
distribute the Library is void, and will automatically terminate your
rights under this License.  However, parties who have received copies,
or rights, from you under this License will not have their licenses
terminated so long as such parties remain in full compliance.

  9. You are not required to accept this License, since you have not
signed it.  However, nothing else grants you permission to modify or
distribute the Library or its derivative works.  These actions are
prohibited by law if you do not accept this License.  Therefore, by
modifying or distributing the Library (or any work based on the
Library), you indicate your acceptance of this License to do so, and
all its terms and conditions for copying, distributing or modifying
the Library or works based on it.

  10. Each time you redistribute the Library (or any work based on the
Library), the recipient automatically receives a license from the
original licensor to copy, distribute, link with or modify the Library
subject to these terms and conditions.  You may not impose any further
restrictions on the recipients' exercise of the rights granted herein.
You are not responsible for enforcing compliance by third parties with
this License.

  11. If, as a consequence of a court judgment or allegation of patent
infringement or for any other reason (not limited to patent issues),
conditions are imposed on you (whether by court order, agreement or
otherwise) that contradict the conditions of this License, they do not
excuse you from the conditions of this License.  If you cannot
distribute so as to satisfy simultaneously your obligations under this
License and any other pertinent obligations, then as a consequence you
may not distribute the Library at all.  For example, if a patent
license would not permit royalty-free redistribution of the Library by
all those who receive copies directly or indirectly through you, then
the only way you could satisfy both it and this License would be to
refrain entirely from distribution of the Library.

If any portion of this section is held invalid or unenforceable under any
particular circumstance, the balance of the section is intended to apply,
and the section as a whole is intended to apply in other circumstances.

It is not the purpose of this section to induce you to infringe any
patents or other property right claims or to contest validity of any
such claims; this section has the sole purpose of protecting the
integrity of the free software distribution system which is
implemented by public license practices.  Many people have made
generous contributions to the wide range of software distributed
through that system in reliance on consistent application of that
system; it is up to the author/donor to decide if he or she is willing
to distribute software through any other system and a licensee cannot
impose that choice.

This section is intended to make thoroughly clear what is believed to
be a consequence of the rest of this License.

  12. If the distribution and/or use of the Library is restricted in
certain countries either by patents or by copyrighted interfaces, the
original copyright holder who places the Library under this License may add
an explicit geographical distribution limitation excluding those countries,
so that distribution is permitted only in or among countries not thus
excluded.  In such case, this License incorporates the limitation as if
written in the body of this License.

  13. The Free Software Foundation may publish revised and/or new
versions of the Lesser General Public License from time to time.
Such new versions will be similar in spirit to the present version,
but may differ in detail to address new problems or concerns.

Each version is given a distinguishing version number.  If the Library
specifies a version number of this License which applies to it and
"any later version", you have the option of following the terms and
conditions either of that version or of any later version published by
the Free Software Foundation.  If the Library does not specify a
license version number, you may choose any version ever published by
the Free Software Foundation.

  14. If you wish to incorporate parts of the Library into other free
programs whose distribution conditions are incompatible with these,
write to the author to ask for permission.  For software which is
copyrighted by the Free Software Foundation, write to the Free
Software Foundation; we sometimes make exceptions for this.  Our
decision will be guided by the two goals of preserving the free status
of all derivatives of our free software and of promoting the sharing
and reuse of software generally.

                            NO WARRANTY

  15. BECAUSE THE LIBRARY IS LICENSED FREE OF CHARGE, THERE IS NO
WARRANTY FOR THE LIBRARY, TO THE EXTENT PERMITTED BY APPLICABLE LAW.
EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR
OTHER PARTIES PROVIDE THE LIBRARY "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
LIBRARY IS WITH YOU.  SHOULD THE LIBRARY PROVE DEFECTIVE, YOU ASSUME
THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

  16. IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN
WRITING WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY
AND/OR REDISTRIBUTE THE LIBRARY AS PERMITTED ABOVE, BE LIABLE TO YOU
FOR DAMAGES, INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR
CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE
LIBRARY (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA BEING
RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A
FAILURE OF THE LIBRARY TO OPERATE WITH ANY OTHER SOFTWARE), EVEN IF
SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
DAMAGES.

                     END OF TERMS AND CONDITIONS

           How to Apply These Terms to Your New Libraries

  If you develop a new library, and you want it to be of the greatest
possible use to the public, we recommend making it free software that
everyone can redistribute and change.  You can do so by permitting
redistribution under these terms (or, alternatively, under the terms of the
ordinary General Public License).

  To apply these terms, attach the following notices to the library.  It is
safest to attach them to the start of each source file to most effectively
convey the exclusion of warranty; and each file should have at least the
"copyright" line and a pointer to where the full notice is found.

    <one line to give the library's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

Also add information on how to contact you by electronic and paper mail.

You should also get your employer (if you work as a programmer) or your
school, if any, to sign a "copyright disclaimer" for the library, if
necessary.  Here is a sample; alter the names:

  Yoyodyne, Inc., hereby disclaims all copyright interest in the
  library `Frob' (a library for tweaking knobs) written by James Random Hacker.

  <signature of Ty Coon>, 1 April 1990
  Ty Coon, President of Vice

That's all there is to it!
*/

// ===== WebSdrCapture.h =====
#include <stdint.h>

#ifndef WEBSDR_ENABLE_FINE_TUNE
#define WEBSDR_ENABLE_FINE_TUNE 1
#endif
#ifndef WEBSDR_FINE_SETTLE_MS
#define WEBSDR_FINE_SETTLE_MS 0
#endif
#ifndef WEBSDR_MAC_IDLE_WAIT_US
#define WEBSDR_MAC_IDLE_WAIT_US 10000
#endif
#ifndef WEBSDR_RX_GATE_ENABLE
#define WEBSDR_RX_GATE_ENABLE 1
#endif
#ifndef WEBSDR_RX_GATE_IDLE_US
#define WEBSDR_RX_GATE_IDLE_US 250
#endif

// Original v6 storage shape and public result names are retained so the
// supplied zero-copy serializer and DSP can continue reading iqStorage.words.
struct CaptureStorage {
  volatile uint32_t words[2048];
  volatile uint32_t guard[16];
};
extern CaptureStorage iqStorage;
static_assert(sizeof(CaptureStorage)==0x2040,"Unexpected BANK0 storage size");

enum class IqStatus : uint8_t {
  NotReady=0,Ok,BadSize,Busy,BadContext,WrongClock,MemoryLayout,
  RadioInit,ProfileMismatch,Timeout,StaleDone,CountMismatch,
  NotWritten,Overrun,DisarmFailed,
  UnsupportedRetune,NotAssociated,RadioRestore,PowerSaveControl
};
struct IqResult {
  IqStatus code;
  uint32_t sequence,requested;
  uint32_t armed,done,status,after,cycles;
  uint32_t changed,beyond,guards;
  bool sawLow,valid;
  int64_t sumA,sumB,energy;
  bool radioRestoreOK;
  uint32_t hash;
};

namespace WebSdrCapture {
constexpr uint16_t MinimumMHz=2412, MaximumMHz=2462;
struct BorrowStatus {
  bool ready,busy,memoryLayoutOK,profile,radioRestored,retuneSupported;
  uint16_t requestedMHz,actualCaptureMHz;
  uint8_t gain,apChannel;
  int32_t offset1024;
  uint32_t borrowCount,restoreCount,restoreFailures;
  uint32_t restoreMismatchIndex,restoreExpected,restoreObserved,restoreMask;
  uint32_t beforePbus[3],afterPbus[3];
  bool originalPbusAutomatic;
  uint32_t dataAddress,guardAddress,bssStart;
  uint32_t bufferHash,bufferHashChecks,bufferHashFailures;
  uint32_t borrowCycles;
  // This backend keeps the SDK logical channel at home and directly programs
  // the native PLL for EVERY physical target, including zero offset. Only
  // divider/calibration readback verifies the physical programmed target.
  // A logical channel getter never proves target frequency or RF lock.
  uint8_t captureChannel;
  bool retuneNeeded,retuneVerified,rfRestoreVerified;
  uint32_t retuneCycles,retuneRestoreCycles,retuneCount,retuneRestoreFailures;
  uint8_t fineExpected[3],fineObserved[3];
  bool fineCalibrationDone;
  int16_t nativeOffsetBefore,nativeOffsetAfter;
  uint32_t savedRetuneControl,returnedRetuneControl;
  uint32_t macAdmissionChecks,macBusyRetries,macWaitCycles,macMaxWaitCycles,macAdmissionTimeouts;
  uint8_t macLastIdleMask;
  bool macLastActive;
  uint8_t macHardware410,macHardware1D0;
  uint32_t macImmediateBusyAborts,macHomeBusyObservations;
  uint32_t rxGateCount,rxGateRestoreCount,rxGateFailures,rxGateTimeouts,rxGateRestoreFailures;
  uint32_t rxGateWaitCycles,rxGateMaxWaitCycles,rxGateLastLoanCycles,rxGateProbeCount;
  uint32_t rxGateControlBefore,rxGateControlGated,rxGateControlReturned;
  uint32_t rxGateStopBefore,rxGateStopReturned;
  uint8_t rxGateHardware410,rxGateHardware1D0;
  bool rxGateRestored;
  uint32_t rxSessionLoans,rxSessionRestores,rxSessionChecks,rxSessionReenabled;
  uint32_t rxSessionUnsupported,rxSessionAcquireTimeouts,rxSessionRestoreFailures;
  uint32_t rxSessionControlBefore,rxSessionControlDisabled,rxSessionControlReturned;
  uint32_t rxSessionLastControl,rxSessionSleepFlags,rxSessionLastStage;
  bool rxSessionActive,rxSessionRestored;
  uint32_t pllProgramCount,pllVerificationFailures,pllLogicalChannelFailures;
  uint16_t pllBaseMHz,pllTargetMHz;
  uint8_t logicalChannel;
  uint8_t homeBefore[3],homeExpected[3],homeObserved[3];
  bool pllOnlyBackend,homeBeforeCalibrationDone,homeCalibrationDone;
  bool homeReturnVerified,homeOracleUsed,expectedHomeRxReopen;
  const char *lastError;
};
// These helpers are the source of truth for UI RANGE and command validation.
// WEBSDR_ENABLE_FINE_TUNE=0 limits operation to 5MHz channel centers.
uint8_t tuneStepMHz();
bool supportsFrequency(uint16_t mhz);
bool configure(uint16_t mhz,uint8_t gain);
// Foreground only, with normal IRQ state. Caller owns one PM1/PM0 pair around
// the complete session and must call endSession() after every successful begin,
// including a failed window. No TCP, yielding or PM operations occur inside
// the short ADC IRQ guard. SDK setters themselves are synchronous SDK calls;
// their internal timing is measured, not claimed to have a caller timeout.
bool beginSession();
bool captureWindow(uint16_t mhz,uint16_t words);
// Isolated diagnostic: no ADC/profile/PBUS or IQ-buffer writes. Caller has an
// active PM1/session and still calls endSession() and PM0 on every outcome.
bool probeMacRxGate(uint16_t mhz,uint16_t holdUs=100);
bool endSession();
bool capture(uint16_t words);
const volatile uint32_t *samples();
uint16_t count();
const IqResult &lastResult();
const BorrowStatus &status();
bool memoryLayoutValid();
int16_t signed10(uint32_t value);
void decode(uint32_t word,int16_t &a,int16_t &b);
// Check after TCP/UDP transmission to detect later SDK/transport corruption of
// the reserved zero-copy capture. It does not mutate the captured samples.
bool verifyBufferHash();
}


// ===== WebSdrCaptureStorage.h =====

// Include this header FIRST in the main .ino, before any other initialized
// global object. Include it in exactly one translation unit. The final ELF and
// every capture must prove iqStorage == _data_start == 0x3FFE8000.
CaptureStorage iqStorage __attribute__((section(".data"),used,aligned(4))) =
    {{0x49514350},{0x47554152}};


// ===== FastCrc32.h =====
#include <stddef.h>
#include <stdint.h>

#if __cplusplus < 201703L
#error "FastCrc32 requires C++17 inline variables (Arduino ESP8266 core 3.1.2 default)."
#endif

// CRC-32/ISO-HDLC (IEEE): reflected polynomial 0xEDB88320, initial and final
// XOR 0xFFFFFFFF. CRC of "123456789" is 0xCBF43926.
//
// Keep this as normal const data, without PROGMEM/ICACHE_RODATA_ATTR. ESP8266
// places the table in DRAM .rodata. One C++17 inline variable shares a single
// 1024-byte table across translation units and adds no .data initializer.
// IRQ masking does not disable the instruction cache. This helper allocates
// nothing and calls no SDK or callbacks. The caller still owns IRQ/RF state.
namespace FastCrc32 {
inline constexpr uint32_t Initial = 0xFFFFFFFFu;
inline constexpr uint32_t Table[256] = {
  0x00000000u, 0x77073096u, 0xEE0E612Cu, 0x990951BAu, 0x076DC419u, 0x706AF48Fu, 0xE963A535u, 0x9E6495A3u,
  0x0EDB8832u, 0x79DCB8A4u, 0xE0D5E91Eu, 0x97D2D988u, 0x09B64C2Bu, 0x7EB17CBDu, 0xE7B82D07u, 0x90BF1D91u,
  0x1DB71064u, 0x6AB020F2u, 0xF3B97148u, 0x84BE41DEu, 0x1ADAD47Du, 0x6DDDE4EBu, 0xF4D4B551u, 0x83D385C7u,
  0x136C9856u, 0x646BA8C0u, 0xFD62F97Au, 0x8A65C9ECu, 0x14015C4Fu, 0x63066CD9u, 0xFA0F3D63u, 0x8D080DF5u,
  0x3B6E20C8u, 0x4C69105Eu, 0xD56041E4u, 0xA2677172u, 0x3C03E4D1u, 0x4B04D447u, 0xD20D85FDu, 0xA50AB56Bu,
  0x35B5A8FAu, 0x42B2986Cu, 0xDBBBC9D6u, 0xACBCF940u, 0x32D86CE3u, 0x45DF5C75u, 0xDCD60DCFu, 0xABD13D59u,
  0x26D930ACu, 0x51DE003Au, 0xC8D75180u, 0xBFD06116u, 0x21B4F4B5u, 0x56B3C423u, 0xCFBA9599u, 0xB8BDA50Fu,
  0x2802B89Eu, 0x5F058808u, 0xC60CD9B2u, 0xB10BE924u, 0x2F6F7C87u, 0x58684C11u, 0xC1611DABu, 0xB6662D3Du,
  0x76DC4190u, 0x01DB7106u, 0x98D220BCu, 0xEFD5102Au, 0x71B18589u, 0x06B6B51Fu, 0x9FBFE4A5u, 0xE8B8D433u,
  0x7807C9A2u, 0x0F00F934u, 0x9609A88Eu, 0xE10E9818u, 0x7F6A0DBBu, 0x086D3D2Du, 0x91646C97u, 0xE6635C01u,
  0x6B6B51F4u, 0x1C6C6162u, 0x856530D8u, 0xF262004Eu, 0x6C0695EDu, 0x1B01A57Bu, 0x8208F4C1u, 0xF50FC457u,
  0x65B0D9C6u, 0x12B7E950u, 0x8BBEB8EAu, 0xFCB9887Cu, 0x62DD1DDFu, 0x15DA2D49u, 0x8CD37CF3u, 0xFBD44C65u,
  0x4DB26158u, 0x3AB551CEu, 0xA3BC0074u, 0xD4BB30E2u, 0x4ADFA541u, 0x3DD895D7u, 0xA4D1C46Du, 0xD3D6F4FBu,
  0x4369E96Au, 0x346ED9FCu, 0xAD678846u, 0xDA60B8D0u, 0x44042D73u, 0x33031DE5u, 0xAA0A4C5Fu, 0xDD0D7CC9u,
  0x5005713Cu, 0x270241AAu, 0xBE0B1010u, 0xC90C2086u, 0x5768B525u, 0x206F85B3u, 0xB966D409u, 0xCE61E49Fu,
  0x5EDEF90Eu, 0x29D9C998u, 0xB0D09822u, 0xC7D7A8B4u, 0x59B33D17u, 0x2EB40D81u, 0xB7BD5C3Bu, 0xC0BA6CADu,
  0xEDB88320u, 0x9ABFB3B6u, 0x03B6E20Cu, 0x74B1D29Au, 0xEAD54739u, 0x9DD277AFu, 0x04DB2615u, 0x73DC1683u,
  0xE3630B12u, 0x94643B84u, 0x0D6D6A3Eu, 0x7A6A5AA8u, 0xE40ECF0Bu, 0x9309FF9Du, 0x0A00AE27u, 0x7D079EB1u,
  0xF00F9344u, 0x8708A3D2u, 0x1E01F268u, 0x6906C2FEu, 0xF762575Du, 0x806567CBu, 0x196C3671u, 0x6E6B06E7u,
  0xFED41B76u, 0x89D32BE0u, 0x10DA7A5Au, 0x67DD4ACCu, 0xF9B9DF6Fu, 0x8EBEEFF9u, 0x17B7BE43u, 0x60B08ED5u,
  0xD6D6A3E8u, 0xA1D1937Eu, 0x38D8C2C4u, 0x4FDFF252u, 0xD1BB67F1u, 0xA6BC5767u, 0x3FB506DDu, 0x48B2364Bu,
  0xD80D2BDAu, 0xAF0A1B4Cu, 0x36034AF6u, 0x41047A60u, 0xDF60EFC3u, 0xA867DF55u, 0x316E8EEFu, 0x4669BE79u,
  0xCB61B38Cu, 0xBC66831Au, 0x256FD2A0u, 0x5268E236u, 0xCC0C7795u, 0xBB0B4703u, 0x220216B9u, 0x5505262Fu,
  0xC5BA3BBEu, 0xB2BD0B28u, 0x2BB45A92u, 0x5CB36A04u, 0xC2D7FFA7u, 0xB5D0CF31u, 0x2CD99E8Bu, 0x5BDEAE1Du,
  0x9B64C2B0u, 0xEC63F226u, 0x756AA39Cu, 0x026D930Au, 0x9C0906A9u, 0xEB0E363Fu, 0x72076785u, 0x05005713u,
  0x95BF4A82u, 0xE2B87A14u, 0x7BB12BAEu, 0x0CB61B38u, 0x92D28E9Bu, 0xE5D5BE0Du, 0x7CDCEFB7u, 0x0BDBDF21u,
  0x86D3D2D4u, 0xF1D4E242u, 0x68DDB3F8u, 0x1FDA836Eu, 0x81BE16CDu, 0xF6B9265Bu, 0x6FB077E1u, 0x18B74777u,
  0x88085AE6u, 0xFF0F6A70u, 0x66063BCAu, 0x11010B5Cu, 0x8F659EFFu, 0xF862AE69u, 0x616BFFD3u, 0x166CCF45u,
  0xA00AE278u, 0xD70DD2EEu, 0x4E048354u, 0x3903B3C2u, 0xA7672661u, 0xD06016F7u, 0x4969474Du, 0x3E6E77DBu,
  0xAED16A4Au, 0xD9D65ADCu, 0x40DF0B66u, 0x37D83BF0u, 0xA9BCAE53u, 0xDEBB9EC5u, 0x47B2CF7Fu, 0x30B5FFE9u,
  0xBDBDF21Cu, 0xCABAC28Au, 0x53B39330u, 0x24B4A3A6u, 0xBAD03605u, 0xCDD70693u, 0x54DE5729u, 0x23D967BFu,
  0xB3667A2Eu, 0xC4614AB8u, 0x5D681B02u, 0x2A6F2B94u, 0xB40BBE37u, 0xC30C8EA1u, 0x5A05DF1Bu, 0x2D02EF8Du,
};
static_assert(sizeof(Table) == 1024, "Unexpected CRC table size");

// Takes/returns the unfinalized running CRC, matching the old crc32Byte API.
inline __attribute__((always_inline)) uint32_t updateByte(uint32_t crc,
                                                         uint8_t value) {
  return (crc >> 8) ^ Table[uint8_t(crc ^ value)];
}
inline uint32_t finish(uint32_t crc) { return crc ^ 0xFFFFFFFFu; }
inline uint32_t update(uint32_t crc, const void *data, size_t length) {
  const uint8_t *bytes = static_cast<const uint8_t *>(data);
  for (size_t i = 0; i < length; ++i) crc = updateByte(crc, bytes[i]);
  return crc;
}
inline uint32_t digest(const void *data, size_t length) {
  return finish(update(Initial, data, length));
}

// Read each volatile BANK0 word once and hash its four little-endian bytes,
// exactly matching the previous hashWords implementation and RAW protocol.
inline uint32_t digestWordsLE(const volatile uint32_t *words, size_t count) {
  uint32_t crc = Initial;
  for (size_t i = 0; i < count; ++i) {
    uint32_t word = words[i];
    for (uint8_t byte = 0; byte < 4; ++byte) {
      crc = updateByte(crc, uint8_t(word));
      word >>= 8;
    }
  }
  return finish(crc);
}
}  // namespace FastCrc32


// ===== Esp8266RadioGuard.h =====
#include <Arduino.h>
extern "C" {
#include <user_interface.h>
}

// Experimental single-core guard for short foreground raw-PHY windows.
// This masks CPU interrupts; it is NOT a grant from the Wi-Fi scheduler and
// does not by itself stop autonomous WDEV transmissions or drain TX queues.
// Raw prepare/restore must run inside the same guard. Do not yield, print,
// allocate, change Wi-Fi mode, or invoke SDK network operations while active.
class Esp8266RadioGuard {
 public:
  Esp8266RadioGuard() = default;
  Esp8266RadioGuard(const Esp8266RadioGuard&) = delete;
  Esp8266RadioGuard& operator=(const Esp8266RadioGuard&) = delete;
  ~Esp8266RadioGuard() { if (_active) end(); }

  bool begin(uint32_t maximumUs) {
    if (_active || maximumUs == 0 || maximumUs > 250000UL) return false;
    const uint8_t mode = wifi_get_opmode();
    if (mode != STATION_MODE && mode != SOFTAP_MODE && mode != STATIONAP_MODE)
      return false;
    if ((mode & STATION_MODE) &&
        wifi_station_get_connect_status() != STATION_GOT_IP) return false;
    const uint32_t mhz = system_get_cpu_freq();
    if (mhz != 80 && mhz != 160) return false;
    _entryMode = mode;
    _entryChannel = wifi_get_channel();
    if (_entryChannel < 1 || _entryChannel > 14) return false;
    _maximumUs = maximumUs;
    _cpuMHz = mhz;
    _previousPs = maskInterrupts();
    _startCycle = readCycle();
    _active = true;
    return true;
  }

  uint32_t IRAM_ATTR elapsedUs() const {
    return _active ? uint32_t(readCycle() - _startCycle) / _cpuMHz : _elapsedUs;
  }
  bool IRAM_ATTR expired() const { return _active && elapsedUs() >= _maximumUs; }

  // The budget is telemetry, not preemption. The raw loop must remain bounded.
  void IRAM_ATTR end() {
    if (!_active) return;
    _elapsedUs = uint32_t(readCycle() - _startCycle) / _cpuMHz;
    const uint32_t ps = _previousPs;
    _active = false;
    restoreInterrupts(ps);
    ++_windows;
    if (_elapsedUs > _maximumUs) ++_overruns;
  }

  bool active() const { return _active; }
  uint32_t lastElapsedUs() const { return _elapsedUs; }
  uint32_t maximumUs() const { return _maximumUs; }
  uint32_t windows() const { return _windows; }
  uint32_t overruns() const { return _overruns; }
  uint8_t entryMode() const { return _entryMode; }
  uint8_t entryChannel() const { return _entryChannel; }

 private:
  static uint32_t IRAM_ATTR maskInterrupts() {
    uint32_t previous;
    __asm__ __volatile__("rsil %0, 15" : "=a"(previous) :: "memory");
    return previous;
  }
  static void IRAM_ATTR restoreInterrupts(uint32_t previous) {
    __asm__ __volatile__("wsr %0, ps\n\trsync" :: "a"(previous) : "memory");
  }
  static uint32_t IRAM_ATTR readCycle() {
    uint32_t cycle;
    __asm__ __volatile__("rsr %0, ccount" : "=a"(cycle));
    return cycle;
  }
  bool _active = false;
  uint8_t _entryMode = 0, _entryChannel = 0;
  uint32_t _previousPs = 0, _startCycle = 0, _cpuMHz = 160;
  uint32_t _maximumUs = 0, _elapsedUs = 0, _windows = 0, _overruns = 0;
};

namespace Esp8266PmNull {
// The SDK callback reports a TX status byte. It is not independently proven
// here to mean reception/ACK by the AP. Keep AP confirmation separate.
struct Snapshot {
  uint32_t submitted;
  uint32_t completed;
  uint8_t txStatus;
  bool pending;
  bool requestedPowerSave;
  bool apPowerSaveConfirmed;
};
static volatile uint32_t submitted = 0, completed = 0;
static volatile uint8_t txStatus = 255;
static volatile bool pending = false, requestedPowerSave = false;
static uint8_t frame[24];

static void IRAM_ATTR txDone(uint8_t status) {
  txStatus = status;
  pending = false;
  ++completed;
}

// Foreground-only; use in the isolated bench, which owns the freedom callback.
// Returns the SDK submission result, or -1001 (role), -1002 (busy),
// -1003 (addresses), -1004 (callback registration).
static int queueWithBssid(bool powerSave, const uint8_t bssid[6]) {
  if (wifi_get_opmode() != STATION_MODE ||
      wifi_station_get_connect_status() != STATION_GOT_IP) return -1001;
  if (pending) return -1002;
  uint8_t own[6];
  if (!bssid || !wifi_get_macaddr(STATION_IF, own)) return -1003;
  bool any = false;
  for (uint8_t i = 0; i < 6; ++i) any |= bssid[i] != 0;
  if (!any || (bssid[0] & 1)) return -1003;
  for (uint8_t i = 0; i < sizeof(frame); ++i) frame[i] = 0;
  frame[0] = 0x48;                       // Data / Null Function (no data).
  frame[1] = 0x01 | (powerSave ? 0x10 : 0); // ToDS, Power Management bit.
  for (uint8_t i = 0; i < 6; ++i) {
    frame[4 + i] = bssid[i];             // RA / BSSID.
    frame[10 + i] = own[i];              // TA / station MAC.
    frame[16 + i] = bssid[i];            // DA, no MSDU payload.
  }
  if (wifi_register_send_pkt_freedom_cb(txDone) != 0) return -1004;
  requestedPowerSave = powerSave;
  txStatus = 255;
  pending = true;
  const int rc = wifi_send_pkt_freedom(frame, sizeof(frame), true);
  if (rc != 0) pending = false;
  else ++submitted;
  return rc;
}

static Snapshot snapshot() {
  return { submitted, completed, txStatus, pending, requestedPowerSave, false };
}
}  // namespace Esp8266PmNull


// ===== WifiContextSnapshot.h =====
#include <Arduino.h>
#include <string.h>
extern "C" {
#include <user_interface.h>
}

// Read-only station observations. Capture in setup/loop with normal IRQ state,
// before the raw capture and after radio restoration / network transfer.
// There are no writable initialized globals here: BANK0 must stay first .data.
namespace WifiContextSnapshot {
struct Value {
  bool valid;
  uint8_t mode, channel, stationStatus;
  uint8_t stationMac[6], bssid[6];
  uint32_t ip, netmask, gateway;
  uint32_t boot, associations, disconnects, gotIpEvents;
};

static bool validUnicast(const uint8_t mac[6]) {
  if (!mac || (mac[0] & 1)) return false;
  uint8_t any = 0;
  for (uint8_t i = 0; i < 6; ++i) any |= mac[i];
  return any != 0;
}

static Value read(const uint8_t actualBssid[6], uint32_t boot,
                  uint32_t associations, uint32_t disconnects,
                  uint32_t gotIpEvents) {
  Value out = {};
  out.boot = boot;
  out.associations = associations;
  out.disconnects = disconnects;
  out.gotIpEvents = gotIpEvents;
  out.mode = wifi_get_opmode();
  out.channel = wifi_get_channel();
  out.stationStatus = uint8_t(wifi_station_get_connect_status());
  if (!(out.mode & STATION_MODE) || !validUnicast(actualBssid)) return out;
  if (!wifi_get_macaddr(STATION_IF, out.stationMac)) return out;
  memcpy(out.bssid, actualBssid, 6);
  ip_info network = {};
  if (!wifi_get_ip_info(STATION_IF, &network)) return out;
  out.ip = network.ip.addr;
  out.netmask = network.netmask.addr;
  out.gateway = network.gw.addr;
  out.valid = out.stationStatus == STATION_GOT_IP &&
              out.channel >= 1 && out.channel <= 14 &&
              validUnicast(out.stationMac) && out.ip != 0;
  return out;
}

// Counters come from the existing SDK event handler; this helper installs no
// second handler and never initiates association, DHCP or network traffic.
static bool sameConnection(const Value& before, const Value& after) {
  return before.valid && after.valid &&
    before.mode == after.mode && before.channel == after.channel &&
    before.stationStatus == after.stationStatus &&
    memcmp(before.stationMac, after.stationMac, 6) == 0 &&
    memcmp(before.bssid, after.bssid, 6) == 0 &&
    before.ip == after.ip && before.netmask == after.netmask &&
    before.gateway == after.gateway && before.boot == after.boot &&
    before.associations == after.associations &&
    before.disconnects == after.disconnects &&
    before.gotIpEvents == after.gotIpEvents;
}
}  // namespace WifiContextSnapshot


// ===== PowerSaveControl.h =====
#include <Arduino.h>

// Foreground/CONT only. This component owns the freedom-frame callback through
// Esp8266PmNull; include/use this in the single owning translation unit, and
// do not queue freedom frames from another component or callback concurrently.
// No WebSocket, UART, Wi-Fi reconnection, allocation or RF register operations.
namespace PowerSaveControl {
constexpr uint32_t AttemptTimeoutUs = 150000u;
constexpr uint8_t MaxAttempts = 3;
constexpr uint32_t RetryBackoffUs = 10000u;

struct Stats {
  uint32_t calls, attempts, retries, txErrors, queueErrors, timeouts, failures;
  int lastQueueRc;
  uint8_t lastTxStatus;
  uint32_t lastWaitUs, lastAttempts;
  uint32_t backoffCount, backoffTotalUs;
};
namespace detail {
// Zero-initialized BSS; nothing here can precede BANK0 in initialized .data.
static Stats state;
static bool active;
static uint32_t seenCompleted;

static bool associated() {
  return wifi_get_opmode() == STATION_MODE &&
         wifi_station_get_connect_status() == STATION_GOT_IP;
}
static void accountCompletion(const Esp8266PmNull::Snapshot &value) {
  if (value.completed == seenCompleted) return;
  seenCompleted = value.completed;
  // The SDK defines zero as send success and every nonzero status as failure.
  // Account late completions too, without counting the same callback twice.
  if (value.txStatus != 0) ++state.txErrors;
}
static Esp8266PmNull::Snapshot waitForCompletion(uint32_t previousCompleted) {
  const uint32_t start = micros();
  auto value = Esp8266PmNull::snapshot();
  while ((value.pending || value.completed == previousCompleted) &&
         uint32_t(micros() - start) < AttemptTimeoutUs) {
    yield();
    value = Esp8266PmNull::snapshot();
  }
  accountCompletion(value);
  return value;
}
}  // namespace detail

static const Stats &stats() { return detail::state; }

// Returns true only after a completed status-zero TX and an associated STA.
// A status failure may mean a missed ACK although the AP received the NULL;
// repeating the same PM value is safe and does not repeat captured payloads.
//
// Retries are permitted only after callback completion, or after a queue error
// with pending=false. A timeout NEVER clears pending or reuses the 24-byte
// frame. A later call first waits up to 150ms for that outstanding callback.
// There are at most 3 actual queue attempts per call (up to 450ms of TX waits),
// plus at most 20ms backoff between completed nonzero TX-status attempts and
// at most 150ms to recover an outstanding previous call: 620ms of programmed
// waits in total. lastWaitUs covers the full call; scheduling can extend wall
// time. lastAttempts counts actual queue calls, including rejections.
static bool send(bool powerSave, const uint8_t bssid[6]) {
  auto &state = detail::state;
  if (detail::active) {
    // Re-entry is a programming error; never steal the outer call's frame.
    ++state.failures;
    return false;
  }
  ++state.calls;
  state.lastQueueRc = 0;
  state.lastTxStatus = 255;
  state.lastWaitUs = 0;
  state.lastAttempts = 0;
  const uint32_t started = micros();
  detail::active = true;
  const auto finish = [&](bool ok) {
    state.lastWaitUs = uint32_t(micros() - started);
    if (!ok) ++state.failures;
    detail::active = false;
    return ok;
  };
  if (!can_yield()) {
    state.lastQueueRc = -1005;  // Local invalid execution context.
    return finish(false);
  }
  auto outstanding = Esp8266PmNull::snapshot();
  detail::accountCompletion(outstanding);
  if (outstanding.pending) {
    const uint32_t previous = outstanding.completed;
    outstanding = detail::waitForCompletion(previous);
    state.lastTxStatus = outstanding.txStatus;
    if (outstanding.pending || outstanding.completed == previous) {
      ++state.timeouts;
      state.lastQueueRc = -1002;  // Existing frame still owned by the SDK.
      return finish(false);
    }
  }

  for (uint8_t attempt = 0; attempt < MaxAttempts; ++attempt) {
    if (!detail::associated()) {
      state.lastQueueRc = -1001;
      return finish(false);
    }
    const auto before = Esp8266PmNull::snapshot();
    if (before.pending) {
      // No concurrent producer is allowed. Fail closed if ownership changed.
      state.lastQueueRc = -1002;
      return finish(false);
    }
    if (attempt) ++state.retries;
    ++state.attempts;
    ++state.lastAttempts;
    state.lastTxStatus = 255;
    const int queued = Esp8266PmNull::queueWithBssid(powerSave, bssid);
    state.lastQueueRc = queued;
    if (queued != 0) {
      ++state.queueErrors;
      const auto after = Esp8266PmNull::snapshot();
      detail::accountCompletion(after);
      if (after.pending || attempt + 1u == MaxAttempts) return finish(false);
      yield();
      continue;
    }
    const auto after = detail::waitForCompletion(before.completed);
    state.lastTxStatus = after.txStatus;
    if (after.pending || after.completed == before.completed) {
      ++state.timeouts;
      return finish(false);  // Preserve SDK ownership, no timeout retry.
    }
    if (!detail::associated()) return finish(false);
    if (after.txStatus == 0) return finish(true);
    if (attempt + 1u == MaxAttempts) return finish(false);
    // Completion released the SDK's ownership and pending is already false.
    // Back off only here; never retry a timeout, add attempts, delay success,
    // or reuse a still-pending frame. The loop rechecks ownership afterwards.
    const uint32_t backoffStarted = micros();
    ++state.backoffCount;
    delay(RetryBackoffUs / 1000u);
    state.backoffTotalUs += uint32_t(micros() - backoffStarted);
  }
  return finish(false);
}
}  // namespace PowerSaveControl


// ===== NetworkWebSocketLink.h =====
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <lwip/tcp.h>

// Standalone ESP8266 core-only WebSocket byte-stream transport.
// Handshake/frame-header algorithms adapted from Links2004/arduinoWebSockets
// 2.7.2, Copyright (c) 2015 Markus Sattler, LGPL-2.1-or-later.
// The incremental parser and bounded single-client transport are adaptations.
// This file is free software under LGPL version 2.1 or any later version.
// It is supplied without warranty; see the accompanying COPYING.LESSER.
// Upstream: https://github.com/Links2004/arduinoWebSockets
// Framing: https://www.rfc-editor.org/rfc/rfc6455
class NetworkWebSocketLink : public Print {
 public:
  using Print::write;
  // Include the largest WebSocket header inside one 1460-byte TCP segment.
  // Four bytes are reserved before the payload, in the existing TX RAM budget.
  #ifndef WEBSDR_TX_BYTES
  #define WEBSDR_TX_BYTES 2048
  #endif
  static constexpr size_t TxPrefix = 4, TxCapacity = WEBSDR_TX_BYTES-TxPrefix, RxCapacity = 1024;
  static_assert(WEBSDR_TX_BYTES >= 128 && WEBSDR_TX_BYTES <= 65535, "Invalid TX byte budget");
  struct Stats {
    uint32_t rxBytes=0, txBytes=0, rxOverflow=0, txErrors=0;
    uint32_t disconnects=0, connects=0, rejectedClients=0, framesTx=0, polls=0;
    uint32_t drainTimeouts=0, writeTimeouts=0, rxHighWater=0, lastDrainAck=0;
    uint32_t acceptedBytes=0, wireTxBytes=0, droppedTxBytes=0, endPackets=0;
    uint32_t protocolErrors=0, handshakeErrors=0, pings=0, pongs=0, peerCloses=0;
  };

  explicit NetworkWebSocketLink(uint16_t port=81);
  using MessageHandler=void(*)(const char*,size_t);
  void onMessage(MessageHandler h){_messageHandler=h;}
  bool sendText(const char*data,size_t n,uint32_t timeout=1000){if(sendFrame(1,reinterpret_cast<const uint8_t*>(data),n,timeout))return true;disconnectClient();return false;}
  bool controlEstablished(){return connected()&&_client.status()==ESTABLISHED;}
  bool _pauseInput=false;
  void pauseInput(){_pauseInput=true;}
  bool begin();
  void close();
  void poll();
  bool connected() const;
  uint32_t epoch() const { return _epoch; }
  int available() const { return int(_rxReady); }
  int read();
  size_t write(uint8_t byte) override { return write(&byte, 1); }
  size_t write(const uint8_t *data, size_t length) override;
  void flush();  // Cooperative service; no frame/ACK wait per serializer chunk.
  bool endPacket(uint32_t timeoutMs=3000);
  bool drain(uint32_t timeoutMs=3000);  // Additionally wait once for native TCP ACK.
  void setNoDelay(bool enabled=true);
  const Stats &stats() const { return _stats; }
  size_t pendingTx() const { return _txUsed; }

 private:
  static constexpr uint32_t InputTimeoutMs = 3000;
  static constexpr size_t HeaderLineCapacity = 256, HttpLimit = 2048;
  static bool token(const char *value, const char *wanted);
  static bool validKey(const char *key);
  static bool utf8Byte(uint8_t value, uint8_t &need, uint8_t &low, uint8_t &high);
  static bool validClose(const uint8_t *data, size_t length);
  static size_t frameHeader(uint8_t *header, uint8_t opcode, size_t length);
  static bool acceptKey(const char *key, char output[29]);
  bool wireWrite(WiFiClient &client, const uint8_t *data, size_t length,
                 uint32_t started, uint32_t timeoutMs);
  bool sendFrame(uint8_t opcode, const uint8_t *data, size_t length,
                 uint32_t timeoutMs);
  bool sendPending(uint32_t timeoutMs);
  void failPacket();
  void disconnectClient();
  void resetInput();
  void resetHandshake();
  void rejectCandidate();
  void pollHandshake();
  bool handshakeLine();
  bool finishHandshake();
  void pollFrames();
  bool decodeFrameHeader();
  bool finishFrame();
  void protocolError(uint16_t closeCode=1002);

  MessageHandler _messageHandler=nullptr;
  char _messageBuffer[RxCapacity+1];
  WiFiServer _server;
  mutable WiFiClient _client;
  WiFiClient _candidate;
  Stats _stats;
  uint8_t _rx[RxCapacity], _tx[TxPrefix+TxCapacity], _header[14], _control[125];
  char _httpLine[HeaderLineCapacity], _key[25];
  size_t _rxHead=0, _rxSize=0, _rxReady=0, _txUsed=0;
  size_t _httpUsed=0, _httpTotal=0;
  uint32_t _epoch=0, _packetEpoch=0, _candidateSince=0;
  uint32_t _frameSince=0, _fragmentSince=0;
  uint32_t _frameLength=0, _frameRead=0, _messageLength=0;
  uint8_t _headerUsed=0, _headerNeeded=2, _opcode=0, _fragmentOpcode=0;
  uint8_t _mask[4], _utf8Need=0, _utf8Low=0x80, _utf8High=0xBF;
  uint16_t _httpLines=0;
  bool _started=false, _connected=false, _insidePoll=false, _noDelay=true;
  bool _packetOpen=false, _packetError=false, _lastPacketOK=true;
  bool _candidateActive=false, _httpCR=false, _httpRequest=false;
  bool _httpHost=false, _httpUpgrade=false, _httpConnection=false;
  bool _httpVersion=false, _httpKey=false, _frameReady=false, _fin=false;
};


// ===== NetworkWebSocketLink.cpp =====

#include <Hash.h>
#include <base64.h>
#include <ctype.h>
#include <string.h>

NetworkWebSocketLink::NetworkWebSocketLink(uint16_t port) : _server(port) {}

bool NetworkWebSocketLink::begin() {
  if (_started) return true;
  _server.begin();
  _server.setNoDelay(_noDelay);
  _started = true;
  return true;
}

void NetworkWebSocketLink::close() {
  rejectCandidate();
  disconnectClient();
  if (_started) _server.close();
  _started = false;
}

bool NetworkWebSocketLink::connected() const {
  return _connected && _client.connected();
}

void NetworkWebSocketLink::setNoDelay(bool enabled) {
  _noDelay = enabled;
  _server.setNoDelay(enabled);
  if (connected()) { _client.setSync(false); _client.setNoDelay(enabled); }
}

void NetworkWebSocketLink::resetInput() {
  _rxHead = _rxSize = _rxReady = 0;
  _headerUsed = 0; _headerNeeded = 2; _frameReady = false;
  _frameLength = _frameRead = _messageLength = 0;
  _fragmentOpcode = _utf8Need = 0;
  _utf8Low = 0x80; _utf8High = 0xBF;
}

void NetworkWebSocketLink::disconnectClient() {
  if (_connected) ++_stats.disconnects;
  _connected = false;
  _client.abort();
  resetInput();
  if (_packetOpen) { _packetError = true; _lastPacketOK = false; }
  if (_txUsed) {
    _stats.droppedTxBytes += _txUsed; _txUsed = 0; ++_stats.txErrors;
  }
}

void NetworkWebSocketLink::resetHandshake() {
  _httpUsed = _httpTotal = _httpLines = 0;
  _httpCR = _httpRequest = _httpHost = _httpUpgrade = false;
  _httpConnection = _httpVersion = _httpKey = false;
  _key[0] = 0;
}

void NetworkWebSocketLink::rejectCandidate() {
  if (_candidateActive) _candidate.abort();
  _candidateActive = false;
  resetHandshake();
}

bool NetworkWebSocketLink::token(const char *value, const char *wanted) {
  const size_t wantedLength = strlen(wanted);
  while (*value) {
    while (*value == ' ' || *value == '\t' || *value == ',') ++value;
    const char *end = value;
    while (*end && *end != ',') ++end;
    const char *trim = end;
    while (trim > value && (trim[-1] == ' ' || trim[-1] == '\t')) --trim;
    if (size_t(trim-value) == wantedLength && !strncasecmp(value, wanted, wantedLength)) return true;
    value = end;
  }
  return false;
}

bool NetworkWebSocketLink::validKey(const char *key) {
  if (strlen(key) != 24 || key[22] != '=' || key[23] != '=') return false;
  int last = 0;
  for (unsigned i = 0; i < 22; ++i) {
    const unsigned char c = key[i];
    if (c >= 'A' && c <= 'Z') last = c-'A';
    else if (c >= 'a' && c <= 'z') last = c-'a'+26;
    else if (c >= '0' && c <= '9') last = c-'0'+52;
    else if (c == '+') last = 62;
    else if (c == '/') last = 63;
    else return false;
  }
  return (last & 15) == 0;  // Canonical base64 of a 16-byte nonce.
}

// The upstream SHA1(key + GUID) -> base64 algorithm; the primitives below
// are supplied by the installed ESP8266 core, with no added library.
bool NetworkWebSocketLink::acceptKey(const char *key, char output[29]) {
  char material[61];
  if (strlen(key) != 24) return false;
  memcpy(material, key, 24);
  memcpy(material+24, "258EAFA5-E914-47DA-95CA-C5AB0DC85B11", 37);
  uint8_t digest[20];
  sha1(reinterpret_cast<const uint8_t *>(material), 60, digest);
  const String encoded = base64::encode(digest, sizeof(digest), false);
  if (encoded.length() != 28) return false;
  memcpy(output, encoded.c_str(), 29);
  return true;
}

bool NetworkWebSocketLink::wireWrite(WiFiClient &client, const uint8_t *data,
                                    size_t length, uint32_t started, uint32_t timeoutMs) {
  size_t written = 0;
  while (written < length) {
    if (!client.connected()) return false;
    if (uint32_t(millis()-started) >= timeoutMs) { ++_stats.writeTimeouts; return false; }
    const int room = client.availableForWrite();
    if (room > 0) {
      const size_t count = min(size_t(room), length-written);
      const size_t sent = client.write(data+written, count);
      if (sent > count) return false;
      written += sent; _stats.wireTxBytes += sent;
    }
    if (written < length) delay(1);  // SDK ACK processing, never application dispatch.
  }
  return true;
}

bool NetworkWebSocketLink::handshakeLine() {
  _httpLine[_httpUsed] = 0;
  if (!_httpLines++) {
    _httpRequest = !strcmp(_httpLine, "GET /ws HTTP/1.1");
    return _httpRequest;
  }
  if (!_httpUsed) return finishHandshake();
  if (_httpLine[0] == ' ' || _httpLine[0] == '\t') return false;
  char *colon = strchr(_httpLine, ':');
  if (!colon) return false;
  *colon = 0;
  for (const char *p = _httpLine; *p; ++p) {
    const unsigned char c = *p;
    if (!isalnum(c) && !strchr("!#$%&'*+-.^_`|~", c)) return false;
  }
  char *value = colon+1;
  while (*value == ' ' || *value == '\t') ++value;
  char *end = value+strlen(value);
  while (end > value && (end[-1] == ' ' || end[-1] == '\t')) *--end = 0;
  if (!strcasecmp(_httpLine, "Host")) {
    if (_httpHost || !*value) return false;
    _httpHost = true;
  } else if (!strcasecmp(_httpLine, "Upgrade")) {
    _httpUpgrade |= token(value, "websocket");
  } else if (!strcasecmp(_httpLine, "Connection")) {
    _httpConnection |= token(value, "Upgrade");
  } else if (!strcasecmp(_httpLine, "Sec-WebSocket-Version")) {
    if (_httpVersion || strcmp(value, "13")) return false;
    _httpVersion = true;
  } else if (!strcasecmp(_httpLine, "Sec-WebSocket-Key")) {
    if (_httpKey || !validKey(value)) return false;
    memcpy(_key, value, 25); _httpKey = true;
  } else if (!strcasecmp(_httpLine, "Content-Length")) {
    if (strcmp(value, "0")) return false;
  } else if (!strcasecmp(_httpLine, "Transfer-Encoding")) return false;
  return true;
}

bool NetworkWebSocketLink::finishHandshake() {
  if (!_httpRequest || !_httpHost || !_httpUpgrade || !_httpConnection || !_httpVersion || !_httpKey) return false;
  char accept[29], response[192];
  if (!acceptKey(_key, accept)) return false;
  const int length = snprintf(response, sizeof(response),
    "HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Accept: %s\r\n\r\n", accept);
  if (length <= 0 || size_t(length) >= sizeof(response)) return false;
  if (!wireWrite(_candidate, reinterpret_cast<const uint8_t *>(response), size_t(length), millis(), 250)) return false;
  _client = _candidate;
  _candidate = WiFiClient();
  _candidateActive = false;
  _connected = true;
  ++_epoch; ++_stats.connects;
  resetInput();
  return true;
}

void NetworkWebSocketLink::pollHandshake() {
  if (!_candidateActive) return;
  if (!_candidate.connected() || uint32_t(millis()-_candidateSince) >= InputTimeoutMs) {
    ++_stats.handshakeErrors; rejectCandidate(); return;
  }
  unsigned budget = 512;
  while (_candidateActive && budget-- && _candidate.available()) {
    const int next = _candidate.read();
    if (next < 0) break;
    const uint8_t c = uint8_t(next);
    if (++_httpTotal > HttpLimit) { ++_stats.handshakeErrors; rejectCandidate(); break; }
    if (c == '\n') {
      if (!_httpCR || !handshakeLine()) { ++_stats.handshakeErrors; rejectCandidate(); break; }
      _httpUsed = 0; _httpCR = false;
    } else if (c == '\r') {
      if (_httpCR) { ++_stats.handshakeErrors; rejectCandidate(); break; }
      _httpCR = true;
    } else {
      if (_httpCR || (c < 32 && c != '\t') || c == 127 || _httpUsed >= HeaderLineCapacity-1) {
        ++_stats.handshakeErrors; rejectCandidate(); break;
      }
      _httpLine[_httpUsed++] = char(c);
    }
  }
}

bool NetworkWebSocketLink::utf8Byte(uint8_t value, uint8_t &need, uint8_t &low, uint8_t &high) {
  if (need) {
    if (value < low || value > high) return false;
    --need; low = 0x80; high = 0xBF; return true;
  }
  low = 0x80; high = 0xBF;
  if (value < 0x80) return true;
  if (value >= 0xC2 && value <= 0xDF) { need = 1; return true; }
  if (value >= 0xE0 && value <= 0xEF) {
    need = 2; if (value == 0xE0) low = 0xA0; if (value == 0xED) high = 0x9F; return true;
  }
  if (value >= 0xF0 && value <= 0xF4) {
    need = 3; if (value == 0xF0) low = 0x90; if (value == 0xF4) high = 0x8F; return true;
  }
  return false;
}

bool NetworkWebSocketLink::validClose(const uint8_t *data, size_t length) {
  if (length == 1) return false;
  if (length >= 2) {
    const uint16_t code = uint16_t(data[0]) << 8 | data[1];
    if (code < 1000 || code >= 5000 || code == 1004 || code == 1005 || code == 1006 || code == 1015 ||
        (code >= 1016 && code < 3000)) return false;
    uint8_t need=0, low=0x80, high=0xBF;
    for (size_t i=2; i<length; ++i) if (!utf8Byte(data[i], need, low, high)) return false;
    if (need) return false;
  }
  return true;
}

// Adapted upstream createHeader() server-side form: FIN, no masking, up to
// 65535 bytes. Data frames include their header in a <=1460-byte wire write.
size_t NetworkWebSocketLink::frameHeader(uint8_t *header, uint8_t opcode, size_t length) {
  header[0] = uint8_t(0x80 | opcode);
  if (length < 126) { header[1] = uint8_t(length); return 2; }
  header[1] = 126; header[2] = uint8_t(length >> 8); header[3] = uint8_t(length); return 4;
}

bool NetworkWebSocketLink::sendFrame(uint8_t opcode, const uint8_t *data, size_t length, uint32_t timeoutMs) {
  if (!connected() || !timeoutMs || length > 4096u || (opcode >= 8 && length > 125u) || (data == _tx+TxPrefix && length > TxCapacity)) return false;
  // Reuse the owned TX buffer to emit small JSON frames with their header in one TCP write.
  if(opcode==1 && data!=_tx+TxPrefix && length<=TxCapacity && !_packetOpen){memcpy(_tx+TxPrefix,data,length);data=_tx+TxPrefix;}
  uint8_t header[4];
  const size_t headerSize = frameHeader(header, opcode, length);
  const uint32_t started = millis();
  if (data == _tx+TxPrefix) {
    // TCP_NODELAY would otherwise emit a tiny header write followed by a
    // payload crossing the MSS boundary. The reserved prefix lets lwIP copy
    // one contiguous frame without a second buffer or any payload conversion.
    uint8_t *frame = _tx+TxPrefix-headerSize;
    memcpy(frame, header, headerSize);
    return wireWrite(_client, frame, headerSize+length, started, timeoutMs);
  }
  return wireWrite(_client, header, headerSize, started, timeoutMs) &&
         (!length || wireWrite(_client, data, length, started, timeoutMs));
}

void NetworkWebSocketLink::protocolError(uint16_t closeCode) {
  ++_stats.protocolErrors;
  const uint8_t code[2] = {uint8_t(closeCode >> 8), uint8_t(closeCode)};
  if (connected() && sendFrame(8, code, sizeof(code), 100)) _client.flush(50);
  disconnectClient();
}

bool NetworkWebSocketLink::decodeFrameHeader() {
  const uint8_t first = _header[0], second = _header[1];
  _fin = first & 0x80; _opcode = first & 15;
  const uint8_t marker = second & 127;
  if ((first & 0x70) || !(second & 0x80) ||
      !(_opcode == 0 || _opcode == 1 || _opcode == 2 || _opcode == 8 || _opcode == 9 || _opcode == 10)) {
    protocolError(); return false;
  }
  if (marker == 127) { ++_stats.rxOverflow; protocolError(1009); return false; }
  _frameLength = marker == 126 ? uint32_t(_header[2]) << 8 | _header[3] : marker;
  if (marker == 126 && _frameLength < 126) { protocolError(); return false; }
  if (_opcode >= 8) {
    if (!_fin || _frameLength > 125 || (_opcode == 8 && _frameLength == 1)) { protocolError(); return false; }
  } else {
    if (_opcode == 0) {
      if (!_fragmentOpcode) { protocolError(); return false; }
    } else {
      if (_fragmentOpcode) { protocolError(); return false; }
      _messageLength = 0; _utf8Need = 0; _utf8Low = 0x80; _utf8High = 0xBF;
    }
    if (_frameLength > RxCapacity-_rxSize || _frameLength > RxCapacity-_messageLength) {
      ++_stats.rxOverflow; protocolError(1009); return false;
    }
    if (_opcode && !_fin) { _fragmentOpcode = _opcode; _fragmentSince = millis(); }
  }
  const size_t maskAt = marker == 126 ? 4 : 2;
  memcpy(_mask, _header+maskAt, 4);
  _frameRead = 0; _frameReady = true;
  return true;
}

bool NetworkWebSocketLink::finishFrame() {
  if (_opcode >= 8) {
    if (_opcode == 9) {
      ++_stats.pings;
      if (!sendFrame(10, _control, _frameLength, 250)) { failPacket(); return false; }
      ++_stats.pongs;
    } else if (_opcode == 8) {
      if (!validClose(_control, _frameLength)) { protocolError(); return false; }
      ++_stats.peerCloses;
      if (sendFrame(8, _control, _frameLength, 100)) _client.flush(50);
      disconnectClient(); return false;
    }
  } else if (_fin) {
    const uint8_t messageOpcode = _opcode ? _opcode : _fragmentOpcode;
    if (messageOpcode == 1 && _utf8Need) { protocolError(1007); return false; }
    _rxReady = _rxSize;  // Commit only a complete, validated message.
    _stats.rxBytes += _messageLength;
    _stats.rxHighWater = max(_stats.rxHighWater, uint32_t(_rxReady));
    _fragmentOpcode = 0; _messageLength = 0;
    if(_messageHandler){
      if(messageOpcode!=1){protocolError(1003);return false;}
      size_t used=0;while(available()&&used<RxCapacity){int b=read();if(b<0)break;_messageBuffer[used++]=char(b);}
      _messageBuffer[used]=0;_messageHandler(_messageBuffer,used);
    }
  }
  _headerUsed = 0; _headerNeeded = 2; _frameReady = false;
  return true;
}

void NetworkWebSocketLink::pollFrames() {
  if (!connected()) return;
  if ((_headerUsed && uint32_t(millis()-_frameSince) >= InputTimeoutMs) ||
      (_fragmentOpcode && uint32_t(millis()-_fragmentSince) >= InputTimeoutMs)) {
    protocolError(); return;
  }
  unsigned budget = 1024;
  while (connected() && !_pauseInput && budget-- && _client.available()) {
    const int next = _client.read();
    if (next < 0) break;
    if (!_frameReady) {
      if (!_headerUsed) _frameSince = millis();
      _header[_headerUsed++] = uint8_t(next);
      if (_headerUsed == 2) {
        const uint8_t marker = _header[1] & 127;
        if ((_header[0] & 0x70) || !(_header[1] & 0x80)) { protocolError(); return; }
        if (marker == 127) { ++_stats.rxOverflow; protocolError(1009); return; }
        _headerNeeded = uint8_t(2 + (marker == 126 ? 2 : marker == 127 ? 8 : 0) + 4);
      }
      if (_headerUsed == _headerNeeded) {
        if (!decodeFrameHeader()) return;
        if (!_frameLength && !finishFrame()) return;
      }
    } else {
      const uint8_t value = uint8_t(next) ^ _mask[_frameRead & 3];
      if (_opcode >= 8) _control[_frameRead] = value;
      else {
        const uint8_t messageOpcode = _opcode ? _opcode : _fragmentOpcode;
        if (messageOpcode == 1 && !utf8Byte(value, _utf8Need, _utf8Low, _utf8High)) { protocolError(1007); return; }
        _rx[(_rxHead+_rxSize) % RxCapacity] = value;
        ++_rxSize; ++_messageLength;
      }
      if (++_frameRead == _frameLength && !finishFrame()) return;
    }
  }
}

void NetworkWebSocketLink::poll() {
  if (!_started || _insidePoll) return;
  _insidePoll = true; _pauseInput=false; ++_stats.polls;
  if (_connected && !_client.connected()) disconnectClient();
  // One accept per poll bounds work even if several peers are connecting.
  if (_server.hasClient()) {
    WiFiClient incoming = _server.accept();
    if (connected() || _candidateActive || _packetOpen) {
      ++_stats.rejectedClients; incoming.abort();
    } else {
      _candidate = incoming; _candidate.setSync(false); _candidate.setNoDelay(_noDelay);
      _candidateActive = true; _candidateSince = millis(); resetHandshake();
    }
  }
  pollHandshake();
  pollFrames();
  _insidePoll = false;
  yield();  // One cooperative SDK turn, without a fixed millisecond pause.
}

int NetworkWebSocketLink::read() {
  if (!_rxReady) return -1;
  const uint8_t byte = _rx[_rxHead];
  _rxHead = (_rxHead+1) % RxCapacity; --_rxReady; --_rxSize;
  return byte;
}

void NetworkWebSocketLink::failPacket() {
  ++_stats.txErrors; _packetError = true; _lastPacketOK = false;
  _stats.droppedTxBytes += _txUsed; _txUsed = 0;
  disconnectClient();
}

bool NetworkWebSocketLink::sendPending(uint32_t timeoutMs) {
  if (!_txUsed) return !_packetError && connected() && _epoch == _packetEpoch;
  if (!_packetOpen || _packetError || !connected() || _epoch != _packetEpoch) { failPacket(); return false; }
  const size_t length = _txUsed;
  if (!sendFrame(2, _tx+TxPrefix, length, timeoutMs)) { failPacket(); return false; }
  _txUsed = 0; _stats.txBytes += length; ++_stats.framesTx;
  poll(); return !_packetError && connected() && _epoch == _packetEpoch;
}

size_t NetworkWebSocketLink::write(const uint8_t *data, size_t length) {
  if (!data || !length) return 0;
  if (!connected()) { ++_stats.txErrors; _lastPacketOK = false; return 0; }
  if (!_packetOpen) { _packetOpen = true; _packetEpoch = _epoch; _packetError = false; _lastPacketOK = true; }
  const uint32_t started = millis();
  size_t copied = 0;
  while (copied < length) {
    if (_packetError || !connected() || _epoch != _packetEpoch) return copied;
    const size_t count = min(TxCapacity-_txUsed, length-copied);
    memcpy(_tx+TxPrefix+_txUsed, data+copied, count);
    _txUsed += count; copied += count; _stats.acceptedBytes += count;
    if (_txUsed == TxCapacity) {
      const uint32_t elapsed = millis()-started;
      if (elapsed >= 3000) { ++_stats.writeTimeouts; failPacket(); return copied-count; }
      if (!sendPending(3000-elapsed)) return copied-count;
    }
  }
  return copied;
}

void NetworkWebSocketLink::flush() { poll(); }

bool NetworkWebSocketLink::endPacket(uint32_t timeoutMs) {
  if (!_packetOpen) return connected() && _lastPacketOK;
  bool ok = timeoutMs && !_packetError && connected() && _epoch == _packetEpoch;
  if (ok) ok = sendPending(timeoutMs);
  if (!ok && _txUsed) failPacket();
  _packetOpen = false; _lastPacketOK = ok; _stats.lastDrainAck = 0; ++_stats.endPackets;
  return ok;
}

bool NetworkWebSocketLink::drain(uint32_t timeoutMs) {
  const uint32_t started = millis();
  _stats.lastDrainAck = 0;
  if (!timeoutMs || !endPacket(timeoutMs)) return false;
  const uint32_t elapsed = millis()-started;
  if (elapsed >= timeoutMs || !connected()) { ++_stats.drainTimeouts; return false; }
  const uint32_t savedEpoch = _epoch;
  const bool acked = _client.flush(timeoutMs-elapsed);
  poll();
  if (!acked || !connected() || savedEpoch != _epoch) { ++_stats.drainTimeouts; return false; }
  _stats.lastDrainAck = 1;
  return true;
}


// ===== WebSdrCapture.cpp =====


#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <string.h>
extern "C" {
#include <user_interface.h>
extern char _data_start,_bss_start,_bss_end;
// SDK22 exported BSS OBJECT (not a pointer). Only its first flag word is read.
extern uint8_t chip6_sleep_params[];
// SDK22 C bool is an unsigned byte; both routines return explicit0/1.
// lmacIsIdle accepts exactly the8 software queues0..7 (36-byte records).
bool lmacIsActive(void);
bool lmacIsIdle(uint8_t ac);
#if WEBSDR_ENABLE_FINE_TUNE
extern uint8_t chip6_phy_init_ctrl[];
extern int16_t phy_freq_offset;
void set_rf_freq_offset(int xtalSelector,int baseMHz,int offsetQ10MHz);
void ram_rfpll_set_freq(int baseMHz,int xtalSelector,int offsetQ10MHz,uint8_t out[3]);
#endif
}

#if !defined(F_CPU) || F_CPU != 160000000L
#error "WebSDR capture requires CPU160MHz"
#endif
#if !defined(MMU_ICACHE_SIZE) || !defined(MMU_IRAM_SIZE) || MMU_ICACHE_SIZE!=0x8000 || MMU_IRAM_SIZE!=0x8000
#error "WebSDR capture requires 32KB cache +32KB IRAM"
#endif
static_assert(WEBSDR_FINE_SETTLE_MS==0,"Session RX loan forbids explicit off-channel SDK yielding");
static_assert(WEBSDR_ENABLE_FINE_TUNE,"PLL-only backend requires the native fine-frequency API");

namespace WebSdrCapture {
namespace {
constexpr uint32_t Base=0x3FFE8000u,Ctrl=0x3FF20E20u;
constexpr uint32_t IqStatusReg=0x3FF20E24u,Layout=0x3FF20E4Cu,CpuClock=0x3FF00014u;
constexpr uint32_t Arm=1u<<31,Done=1u<<18,Pulse=1u<<19;
constexpr uint32_t PbusCmd=0x60000594u,PbusStat=0x600005A0u,RxCtrl=0x60009B08u;
constexpr uint32_t RxStop=0x08000000u,TimeoutCycles=160000u;
constexpr uint32_t RetuneControl=0x600005C8u,RetuneControlMask=0x00F00000u;
constexpr uint32_t MacRxControl=0x3FF20004u,MacRxEnable=0x80000000u;
constexpr uint16_t MaxWords=2048,GuardWords=16;
// All writable storage in this translation unit remains zero-initialized BSS.
static BorrowStatus state;
static IqResult result;
static bool lastValid,radioFault;
static uint16_t lastWords;
static uint32_t sequence;
struct Session {
  bool active,fineDirty,fineActive;
  uint8_t homeChannel,mode,ownMac[6],bssid[6];
  uint32_t ip,netmask,gateway;
  uint32_t savedRetuneControl;
};
static Session session;
struct RxGateLoan {bool active;uint32_t enable,stop,start;};
static RxGateLoan rxGate;
struct SessionRxLoan {bool active,broken;uint32_t enable;};
static SessionRxLoan sessionRx;
struct Snapshot {uint32_t ctrl,layout,pbusCmd,rxCtrl;uint16_t pbus[3];};
static Snapshot saved;
static inline __attribute__((always_inline)) uint32_t rd(uint32_t a) {
  __asm__ volatile("memw" ::: "memory");return *reinterpret_cast<volatile uint32_t*>(a);
}
static inline __attribute__((always_inline)) void wr(uint32_t a,uint32_t v) {
  *reinterpret_cast<volatile uint32_t*>(a)=v;__asm__ volatile("memw" ::: "memory");
}
static inline __attribute__((always_inline)) uint32_t cycles() {uint32_t x;__asm__ volatile("rsr.ccount %0":"=a"(x));return x;}
static inline uint32_t processorStatus() {uint32_t x;__asm__ volatile("rsr.ps %0":"=a"(x));return x;}
#if WEBSDR_ENABLE_FINE_TUNE
static bool fineReadback(uint8_t xtal,uint16_t baseMHz,int32_t offset);
#endif
static bool macObservedIdle() {
  ++state.macAdmissionChecks;
  state.macLastActive=lmacIsActive();
  uint8_t mask=0;
  for(uint8_t ac=0;ac<8;ac++)if(lmacIsIdle(ac))mask|=uint8_t(1u<<ac);
  state.macLastIdleMask=mask;
  // Same read-only hardware predicates used by SDK22 pm_check_mac_idle().
  state.macHardware410=uint8_t(rd(0x3FF20410u)&0xFu);
  state.macHardware1D0=uint8_t((rd(0x3FF201D0u)>>12)&0xFu);
  return !state.macLastActive&&mask==0xFFu&&!state.macHardware410&&!state.macHardware1D0;
}
static void recordMacWait(uint32_t start,bool timedOut) {
  const uint32_t elapsed=cycles()-start;
  state.macWaitCycles+=elapsed;
  if(elapsed>state.macMaxWaitCycles)state.macMaxWaitCycles=elapsed;
  if(timedOut)++state.macAdmissionTimeouts;
}
// Observation-only admission. On a successful masked check, ownership of the
// saved PS transfers to the ADC caller, which must restore it on every path.
// A busy check restores PS BEFORE yielding/retrying. These software getters
// do not reserve the autonomous radio or alter any hardware TX queue.
static bool awaitMacIdle(bool maskInterrupts,uint32_t *savedPs=nullptr) {
  const uint32_t start=cycles();
  bool retried=false;
  while(true) {
    if(retried&&uint32_t(cycles()-start)>=160u*uint32_t(WEBSDR_MAC_IDLE_WAIT_US)) {
      recordMacWait(start,true);return false;
    }
    // A previous busy observation may have yielded to SDK tasks. Re-check
    // requested channel/fine state BEFORE masking, so no analog-I2C poll is
    // introduced inside the bounded ADC IRQ guard.
    if(maskInterrupts) {
      if(wifi_get_channel()!=session.homeChannel||wifi_station_get_connect_status()!=STATION_GOT_IP) {
        state.retuneVerified=false;recordMacWait(start,false);return false;
      }
#if WEBSDR_ENABLE_FINE_TUNE
      if(session.fineActive&&!fineReadback(chip6_phy_init_ctrl[1],
          uint16_t(2407u+5u*state.captureChannel),state.offset1024)) {
        state.retuneVerified=false;recordMacWait(start,false);return false;
      }
#endif
    }
    uint32_t ps=0;
    if(maskInterrupts)__asm__ volatile("rsil %0, 15\n\trsync":"=a"(ps)::"memory");
    if(macObservedIdle()) {
      if(uint32_t(cycles()-start)>=160u*uint32_t(WEBSDR_MAC_IDLE_WAIT_US)) {
        if(maskInterrupts)__asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
        recordMacWait(start,true);return false;
      }
      if(maskInterrupts)*savedPs=ps;
      recordMacWait(start,false);return true;
    }
    if(maskInterrupts)__asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
    ++state.macBusyRetries;
    // Do not run CONT/PP tasks on a foreign channel while waiting for queued
    // traffic which needs the AP. Return promptly so endSession can go home.
    const bool away=session.active&&(wifi_get_channel()!=session.homeChannel||session.fineActive);
    if(maskInterrupts||away||state.rxSessionActive) {
      ++state.macImmediateBusyAborts;recordMacWait(start,false);return false;
    }
    retried=true;
    if(uint32_t(cycles()-start)>=160u*uint32_t(WEBSDR_MAC_IDLE_WAIT_US)) {
      recordMacWait(start,true);return false;
    }
    yield();
  }
}
static uint32_t sessionSleepFlags() {
  const volatile uint8_t *bytes=chip6_sleep_params;
  uint32_t flags=0;
  for(uint8_t i=0;i<4;i++)flags|=uint32_t(bytes[i])<<(8u*i);
  state.rxSessionSleepFlags=flags;return flags;
}
static bool sessionSleepEligible() {
  sessionSleepFlags();
  // The PLL-only path never calls the native channel setter away from home.
  // Its helper does not inspect bit25, so that native-wake flag is telemetry,
  // not a rejection condition. No private sleep flag is modified.
  if(wifi_get_sleep_type()!=NONE_SLEEP_T) {
    ++state.rxSessionUnsupported;return false;
  }
  return true;
}
// Stages:1 acquisition,2 before setter,3 after setter,4 before fine,
// 5 after fine,6 before ADC/probe,7 after ADC/probe,8 before home,9 after home.
// These are boundary observations, not proof of uninterrupted exclusive radio
// ownership. In particular, a reopened RX bit is NEVER silently re-cleared.
static bool observeSessionRx(uint32_t stage,bool checkSleep) {
  ++state.rxSessionChecks;state.rxSessionLastStage=stage;
  state.rxSessionLastControl=rd(MacRxControl);
  bool ok=true;
  if(checkSleep&&!sessionSleepEligible())ok=false;
  state.logicalChannel=wifi_get_channel();
  if(session.active&&state.logicalChannel!=session.homeChannel) {
    ++state.pllLogicalChannelFailures;ok=false;
  }
  if(sessionRx.active&&(state.rxSessionLastControl&MacRxEnable)) {
    ++state.rxSessionReenabled;
    ok=false;
  }
  if(!ok)sessionRx.broken=true;
  return ok&&!sessionRx.broken;
}
static bool releaseSessionRx() {
  if(!sessionRx.active)return state.rxSessionRestored;
  uint32_t ps;__asm__ volatile("rsil %0, 15\n\trsync":"=a"(ps)::"memory");
  wr(MacRxControl,(rd(MacRxControl)&~MacRxEnable)|sessionRx.enable);
  state.rxSessionControlReturned=rd(MacRxControl);
  const bool restored=(state.rxSessionControlReturned&MacRxEnable)==sessionRx.enable;
  sessionRx.active=false;state.rxSessionActive=false;state.rxSessionRestored=restored;
  ++state.rxSessionRestores;
  if(!restored)++state.rxSessionRestoreFailures;
  __asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
  return restored;
}
static bool acquireSessionRx() {
  state.rxSessionRestored=true;sessionRx.broken=false;
  if(!sessionSleepEligible()) {state.lastError="rx_session_sleep_path_unsupported";return false;}
  if(!awaitMacIdle(false)) {state.lastError="mac_busy_before_session_gate";return false;}
  uint32_t ps;__asm__ volatile("rsil %0, 15\n\trsync":"=a"(ps)::"memory");
  sessionSleepFlags();
  const bool unsupportedSleep=wifi_get_sleep_type()!=NONE_SLEEP_T;
  if(unsupportedSleep||!macObservedIdle()) {
    __asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
    if(unsupportedSleep){++state.rxSessionUnsupported;state.lastError="rx_session_sleep_path_unsupported";}
    else {++state.macImmediateBusyAborts;state.lastError="mac_busy_at_session_gate";}
    return false;
  }
  const uint32_t originalStop=rd(RxCtrl)&RxStop;
  state.rxSessionControlBefore=rd(MacRxControl);sessionRx.enable=state.rxSessionControlBefore&MacRxEnable;
  sessionRx.active=true;state.rxSessionActive=true;state.rxSessionRestored=false;++state.rxSessionLoans;
  wr(RxCtrl,rd(RxCtrl)|RxStop);
  wr(MacRxControl,rd(MacRxControl)&~MacRxEnable);
  state.rxSessionControlDisabled=rd(MacRxControl);
  bool ready=!(state.rxSessionControlDisabled&MacRxEnable)&&(rd(RxCtrl)&RxStop);
  const uint32_t start=cycles();
  while(ready) {
    const uint32_t a=rd(0x3FF20410u)&0xFu,b=(rd(0x3FF201D0u)>>12)&0xFu;
    if(!a&&!b)break;
    if(uint32_t(cycles()-start)>=160u*uint32_t(WEBSDR_RX_GATE_IDLE_US)) {
      ++state.rxSessionAcquireTimeouts;ready=false;break;
    }
  }
  // The long loan owns only MAC RX-enable. SDK channel setters legitimately
  // stop/start digital PHY RX; never hold PHY_RX_STOP across those calls.
  wr(RxCtrl,(rd(RxCtrl)&~RxStop)|originalStop);
  ready=ready&&((rd(RxCtrl)&RxStop)==originalStop);
  if(!ready) {
    wr(MacRxControl,(rd(MacRxControl)&~MacRxEnable)|sessionRx.enable);
    state.rxSessionControlReturned=rd(MacRxControl);
    state.rxSessionRestored=((state.rxSessionControlReturned&MacRxEnable)==sessionRx.enable)&&
      ((rd(RxCtrl)&RxStop)==originalStop);
    sessionRx.active=false;state.rxSessionActive=false;++state.rxSessionRestores;
    if(!state.rxSessionRestored)++state.rxSessionRestoreFailures;
    state.lastError="rx_session_gate_acquire_failed";
  }
  __asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
  if(!ready)return false;
  return observeSessionRx(1,true);
}
static uint16_t pbusRead(uint8_t selector,uint8_t bank) {
  using Fn=uint32_t(*)(uint32_t,uint32_t);
  return uint16_t(reinterpret_cast<Fn>(0x400074D8u)(selector,bank)&0x1FFu);
}
static bool pbusWrite(uint8_t selector,uint8_t bank,uint16_t value) {
  uint32_t command=rd(PbusCmd)&0xFFFF0001u;
  command|=uint32_t(bank&3u)<<14;command|=uint32_t(value&0x1FFu)<<5;
  command|=uint32_t(selector&7u)<<2;wr(PbusCmd,command|2u);
  const uint32_t start=cycles();
  while(rd(PbusStat)&0x80000000u) {
    if(uint32_t(cycles()-start)>160u*2500u) {wr(PbusCmd,rd(PbusCmd)&~2u);return false;}
  }
  wr(PbusCmd,rd(PbusCmd)&~2u);return true;
}
static uint16_t gainCoarse(uint8_t index) {
  switch(index/6u) {case 0:return 0;case 1:return 0x40;case 2:return 0x60;case 3:return 0x70;default:return 0x78;}
}
// Temporary hardware RX loan only. Never call wDevDisableRx(), whose native
// implementation also changes an SDK-private software flag. Native sleep
// orders PHY_RX_STOP before clearing this MAC RX-enable bit; preserve that
// order, then wait only on hardware fields while CPU interrupts are masked.
static bool beginRxGate() {
  if(sessionRx.active&&!observeSessionRx(6,false))return false;
  rxGate.active=true;rxGate.start=cycles();++state.rxGateCount;
  state.rxGateRestored=false;
  state.rxGateControlBefore=rd(MacRxControl);state.rxGateStopBefore=rd(RxCtrl);
  rxGate.enable=state.rxGateControlBefore&MacRxEnable;
  rxGate.stop=state.rxGateStopBefore&RxStop;
  wr(RxCtrl,rd(RxCtrl)|RxStop);
  if(!sessionRx.active)wr(MacRxControl,rd(MacRxControl)&~MacRxEnable);
  state.rxGateControlGated=rd(MacRxControl);
  const uint32_t start=cycles();
  if((state.rxGateControlGated&MacRxEnable)||!(rd(RxCtrl)&RxStop)) {
    ++state.rxGateFailures;return false;
  }
  while(true) {
    state.rxGateHardware410=uint8_t(rd(0x3FF20410u)&0xFu);
    state.rxGateHardware1D0=uint8_t((rd(0x3FF201D0u)>>12)&0xFu);
    const uint32_t elapsed=cycles()-start;
    if(!state.rxGateHardware410&&!state.rxGateHardware1D0) {
      state.rxGateWaitCycles+=elapsed;
      if(elapsed>state.rxGateMaxWaitCycles)state.rxGateMaxWaitCycles=elapsed;
      return true;
    }
    if(elapsed>=160u*uint32_t(WEBSDR_RX_GATE_IDLE_US)) {
      state.rxGateWaitCycles+=elapsed;
      if(elapsed>state.rxGateMaxWaitCycles)state.rxGateMaxWaitCycles=elapsed;
      ++state.rxGateTimeouts;++state.rxGateFailures;return false;
    }
  }
}
static bool endRxGate() {
  if(!rxGate.active)return true;
  // The ADC path has already restored its capture/PBUS state. Restore only
  // the two bits we own, preserving all other CURRENT fields in each word.
  wr(RxCtrl,(rd(RxCtrl)&~RxStop)|rxGate.stop);
  const bool violated=sessionRx.active&&!observeSessionRx(7,false);
  if(!sessionRx.active&&!violated)wr(MacRxControl,(rd(MacRxControl)&~MacRxEnable)|rxGate.enable);
  state.rxGateStopReturned=rd(RxCtrl);state.rxGateControlReturned=rd(MacRxControl);
  state.rxGateRestored=(state.rxGateStopReturned&RxStop)==rxGate.stop&&
      (state.rxGateControlReturned&MacRxEnable)==rxGate.enable&&!violated;
  state.rxGateLastLoanCycles=cycles()-rxGate.start;
  rxGate.active=false;++state.rxGateRestoreCount;
  if(!state.rxGateRestored){++state.rxGateRestoreFailures;++state.rxGateFailures;}
  return state.rxGateRestored;
}
static void gateRestoreFault() {
  ++state.restoreFailures;radioFault=true;state.ready=false;state.radioRestored=false;
  lastValid=result.valid=false;lastWords=0;result.radioRestoreOK=false;
  result.code=IqStatus::RadioRestore;state.lastError="rx_gate_restore";
}
static void invalidate(IqStatus code,const char *error) {
  lastValid=false;lastWords=0;result={};result.code=code;
  result.radioRestoreOK=!radioFault;state.lastError=error;
}
static void recordMismatch(uint32_t index,uint32_t actual,uint32_t expected,uint32_t mask=0xFFFFFFFFu) {
  if(((actual^expected)&mask)==0)return;
  if(state.restoreMismatchIndex==0xFFFFFFFFu) {
    state.restoreMismatchIndex=index;state.restoreExpected=expected;
    state.restoreObserved=actual;state.restoreMask=mask;
  }
}
static bool snapshot() {
  if((rd(PbusStat)&0x80000000u)||(rd(PbusCmd)&2u)) {result.code=IqStatus::Busy;state.lastError="pbus_busy";return false;}
  saved.ctrl=rd(Ctrl);saved.layout=rd(Layout);saved.pbusCmd=rd(PbusCmd);saved.rxCtrl=rd(RxCtrl);
  if(saved.ctrl&(Arm|Pulse)) {result.code=IqStatus::Busy;state.lastError="capture_engine_busy";return false;}
  saved.pbus[0]=pbusRead(2,1);saved.pbus[1]=pbusRead(3,1);saved.pbus[2]=pbusRead(3,2);
  for(uint8_t i=0;i<3;i++)state.beforePbus[i]=saved.pbus[i];
  state.originalPbusAutomatic=(saved.pbusCmd&1u)==0;
  ++state.borrowCount;state.radioRestored=false;
  state.restoreMismatchIndex=0xFFFFFFFFu;state.restoreExpected=0;state.restoreObserved=0;state.restoreMask=0;
  return true;
}
static bool applyProfile() {
  // Both supported SDKs have a polling debug entry. This explicitly
  // performs the same controlled RX_STOP/debug entry with bounded PBUS writes.
  wr(RxCtrl,rd(RxCtrl)|RxStop);wr(PbusCmd,rd(PbusCmd)|1u);
  const uint16_t coarse=gainCoarse(state.gain),fine=uint16_t(6u|uint16_t(state.gain%6u)<<3);
  if(!(pbusWrite(2,1,0x1C6)&&pbusWrite(3,1,coarse)&&pbusWrite(3,2,fine)))return false;
  wr(Layout,0x03020100u);
  state.profile=pbusRead(2,1)==0x1C6u&&pbusRead(3,1)==coarse&&pbusRead(3,2)==fine&&rd(Layout)==0x03020100u;
  return state.profile;
}
static bool restoreRadio() {
  bool ok=true;
  wr(Ctrl,rd(Ctrl)&~Arm);
  if(rd(Ctrl)&Arm) {
    recordMismatch(0,rd(Ctrl),saved.ctrl,Arm);
    state.radioRestored=false;++state.restoreFailures;radioFault=true;return false;
  }
  // Preserve normal MAC/debug routing before Wi-Fi resumes. Never call
  // pbus_workmode(), which has SDK MAC callbacks in addition to register writes.
  wr(Ctrl,saved.ctrl&~(Arm|Done|Pulse));wr(Layout,saved.layout);
  wr(PbusCmd,rd(PbusCmd)|1u);
  if(!pbusWrite(2,1,saved.pbus[0]))ok=false;
  if(!pbusWrite(3,1,saved.pbus[1]))ok=false;
  if(!pbusWrite(3,2,saved.pbus[2]))ok=false;
  wr(RxCtrl,saved.rxCtrl);wr(PbusCmd,saved.pbusCmd&~2u);
  recordMismatch(0,rd(Ctrl),saved.ctrl,~Done);
  recordMismatch(1,rd(Layout),saved.layout);
  recordMismatch(2,rd(RxCtrl),saved.rxCtrl);
  recordMismatch(3,rd(PbusCmd),saved.pbusCmd);
  state.afterPbus[0]=pbusRead(2,1);state.afterPbus[1]=pbusRead(3,1);state.afterPbus[2]=pbusRead(3,2);
  // In AUTO mode these values are hardware state, not fixed writable controls.
  // A prior100ms no-write hold already showed STA PBUS2/1 varying1FE->1F4
  // while its WPA/TCP association remained intact. Log them, do not invent a
  // static readback assertion. When returning to DEBUG, exact values do apply.
  if(!state.originalPbusAutomatic)for(uint8_t i=0;i<3;i++)recordMismatch(4u+i,state.afterPbus[i],saved.pbus[i]);
  if(state.restoreMismatchIndex!=0xFFFFFFFFu)ok=false;
  ++state.restoreCount;state.radioRestored=ok;
  if(!ok) {++state.restoreFailures;radioFault=true;}
  return ok;
}
static uint32_t hashWords(uint16_t n) {
  return FastCrc32::digestWordsLE(iqStorage.words,n);
}
static uint8_t nearestChannel(uint16_t mhz) {
  return uint8_t(1u+(mhz-MinimumMHz+2u)/5u);
}
#if WEBSDR_ENABLE_FINE_TUNE
static uint8_t analogRead(uint8_t block,uint8_t host,uint8_t reg) {
  using Fn=uint32_t(*)(uint32_t,uint32_t,uint32_t);
  return uint8_t(reinterpret_cast<Fn>(0x40007268u)(block,host,reg));
}
static bool fineReadback(uint8_t xtal,uint16_t baseMHz,int32_t offset) {
  ram_rfpll_set_freq(int(baseMHz),int(xtal),int(offset),state.fineExpected);
  for(uint8_t i=0;i<3;i++)state.fineObserved[i]=analogRead(0x63,0,uint8_t(3u+i));
  state.fineCalibrationDone=(analogRead(0x62,1,7)&0x80u)!=0;
  return state.fineCalibrationDone&&!memcmp(state.fineExpected,state.fineObserved,3);
}
static void readHomeDivider(uint8_t bytes[3],bool &calibrationDone) {
  for(uint8_t i=0;i<3;i++)bytes[i]=analogRead(0x63,0,uint8_t(3u+i));
  calibrationDone=(analogRead(0x62,1,7)&0x80u)!=0;
}
static bool snapshotHomeDivider() {
  const int16_t before=phy_freq_offset;
  readHomeDivider(state.homeBefore,state.homeBeforeCalibrationDone);
  state.nativeOffsetBefore=phy_freq_offset;
  memcpy(state.homeExpected,state.homeBefore,3);
  state.homeReturnVerified=false;state.homeOracleUsed=false;
  return before==state.nativeOffsetBefore&&state.homeBeforeCalibrationDone;
}
static bool verifyHomeDivider() {
  readHomeDivider(state.homeObserved,state.homeCalibrationDone);
  state.nativeOffsetAfter=phy_freq_offset;
  state.homeOracleUsed=false;
  memcpy(state.homeExpected,state.homeBefore,3);
  // Native zero-CFO table and policy gates are not interchangeable with a
  // guessed generic oracle. This initial experiment accepts only exact saved
  // physical-divider return while the native correction remains unchanged.
  state.homeReturnVerified=state.nativeOffsetAfter==state.nativeOffsetBefore&&
      state.homeCalibrationDone&&!memcmp(state.homeExpected,state.homeObserved,3);
  return state.homeReturnVerified;
}
#endif
}

bool memoryLayoutValid() {
  state.dataAddress=uint32_t(uintptr_t(&iqStorage.words[0]));
  state.guardAddress=uint32_t(uintptr_t(&iqStorage.guard[0]));
  state.bssStart=uint32_t(uintptr_t(&_bss_start));
  state.memoryLayoutOK=uintptr_t(&_data_start)==Base
      &&uintptr_t(&iqStorage.words[0])==Base
      &&uintptr_t(&iqStorage.guard[0])==Base+0x2000u
      &&uintptr_t(&_bss_start)>=Base+sizeof(iqStorage);
  return state.memoryLayoutOK;
}
int16_t signed10(uint32_t value) {value&=0x3FFu;return int16_t(value<512u?int32_t(value):int32_t(value)-1024);}
void decode(uint32_t word,int16_t &a,int16_t &b) {a=signed10(word);b=signed10(word>>10);}
const volatile uint32_t *samples() {return lastValid?iqStorage.words:nullptr;}
uint16_t count() {return lastValid?lastWords:0;}
const IqResult &lastResult() {return result;}
const BorrowStatus &status() {if(!state.lastError)state.lastError="not_configured";return state;}
uint8_t tuneStepMHz() {return WEBSDR_ENABLE_FINE_TUNE?1:5;}
bool supportsFrequency(uint16_t mhz) {
  return mhz>=MinimumMHz&&mhz<=MaximumMHz&&((mhz-MinimumMHz)%tuneStepMHz())==0;
}

bool configure(uint16_t mhz,uint8_t gain) {
  if(state.busy||session.active)return false;
  if(processorStatus()&0x1Fu) {invalidate(IqStatus::BadContext,"not_main_context");return false;}
  state.requestedMHz=mhz;state.gain=gain;state.retuneSupported=true;state.pllOnlyBackend=true;state.ready=false;
  invalidate(IqStatus::NotReady,"not_ready");
  if(radioFault) {invalidate(IqStatus::RadioRestore,"previous_restore_failure");return false;}
  if(!memoryLayoutValid()) {invalidate(IqStatus::MemoryLayout,"bank0_layout");return false;}
  if(!(rd(CpuClock)&1u)) {invalidate(IqStatus::WrongClock,"cpu_not_160mhz");return false;}
  if(!supportsFrequency(mhz)||gain>29u) {invalidate(IqStatus::UnsupportedRetune,"configuration_range_or_step");return false;}
  state.apChannel=wifi_get_channel();state.offset1024=0;
  if(wifi_station_get_connect_status()!=STATION_GOT_IP) {invalidate(IqStatus::NotAssociated,"station_not_connected");return false;}
  if(state.apChannel<1u||state.apChannel>11u) {invalidate(IqStatus::RadioInit,"ap_channel");return false;}
  state.actualCaptureMHz=0;state.captureChannel=nearestChannel(mhz);
  state.offset1024=(int32_t(mhz)-int32_t(2407u+5u*state.captureChannel))*1024;
  state.retuneNeeded=state.captureChannel!=state.apChannel||state.offset1024!=0;
  state.retuneVerified=false;state.rfRestoreVerified=true;
  state.ready=true;result.code=IqStatus::Ok;state.lastError="none";return true;
}

// Existing supplied-v6 acquisition, profile restoration, guards and hash.
// This helper is called only after the foreground SDK channel hop completes.
static bool IRAM_ATTR captureCurrent(uint16_t mhz,uint16_t n) {
  if(state.busy)return false;
  if(processorStatus()&0x1Fu) {invalidate(IqStatus::BadContext,"not_main_context");return false;}
  state.busy=true;invalidate(IqStatus::NotReady,"not_ready");result.requested=n;
  if(!state.ready||radioFault) {if(radioFault)invalidate(IqStatus::RadioRestore,"previous_restore_failure");state.busy=false;return false;}
  if(n<2u||n>MaxWords) {result.code=IqStatus::BadSize;state.lastError="capture_size";state.busy=false;return false;}
  if(!memoryLayoutValid()) {result.code=IqStatus::MemoryLayout;state.lastError="bank0_layout";state.busy=false;return false;}
  if(!(rd(CpuClock)&1u)) {result.code=IqStatus::WrongClock;state.lastError="cpu_not_160mhz";state.busy=false;return false;}
  if(wifi_station_get_connect_status()!=STATION_GOT_IP) {result.code=IqStatus::NotAssociated;state.lastError="station_not_connected";state.busy=false;return false;}
  const uint8_t channel=wifi_get_channel();
  if(channel!=session.homeChannel||!state.retuneVerified) {result.code=IqStatus::RadioInit;state.lastError="logical_home_or_pll_target_mismatch";state.busy=false;return false;}
  state.captureChannel=nearestChannel(mhz);state.logicalChannel=channel;state.actualCaptureMHz=mhz;
  uint32_t ps;
  if(!awaitMacIdle(true,&ps)) {
    result.code=state.retuneVerified?IqStatus::Busy:IqStatus::RadioInit;
    state.lastError=state.retuneVerified?"mac_busy_before_adc":"retune_changed_before_adc";
    state.busy=false;return false;
  }
  if(sessionRx.active&&!observeSessionRx(6,false)) {
    __asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
    result.code=IqStatus::RadioInit;state.lastError="rx_session_reopened_before_adc";state.busy=false;return false;
  }
  const uint32_t borrowStart=cycles();
  const bool haveSnapshot=snapshot();
  if(haveSnapshot) {
    bool profileEntered=false;
    const bool gateReady=WEBSDR_RX_GATE_ENABLE?beginRxGate():true;
    if(!gateReady) {result.code=IqStatus::Busy;state.lastError="rx_gate_not_idle";}
    else {
    profileEntered=true;
    if(!applyProfile()) {result.code=IqStatus::ProfileMismatch;state.lastError="capture_profile";}
    else {
      wr(Ctrl,rd(Ctrl)&~Arm);
      if(rd(Ctrl)&Arm) {result.code=IqStatus::DisarmFailed;state.lastError="capture_disarm";}
      else {
        // Original supplied-v6 sentinels, guard, arm/pulse/count validation.
        result.sequence=++sequence;
        const uint32_t sentinel=0x5AA50000u^((sequence&0xFFFu)<<4);
        for(unsigned i=0;i<MaxWords;i++)wr(Base+i*4u,sentinel^i);
        for(unsigned i=0;i<GuardWords;i++)iqStorage.guard[i]=0xCAFE0000u^sequence^i;
        wr(Ctrl,(uint32_t(n)+1u)|0x8000u);wr(Ctrl,rd(Ctrl)|Arm);
        const uint32_t armed=rd(Ctrl),start=cycles();
        wr(Ctrl,rd(Ctrl)|Pulse);wr(Ctrl,rd(Ctrl)&~Pulse);
        uint32_t done=rd(Ctrl);bool sawLow=!(armed&Done)||!(done&Done);
        while(!(done&Done)&&uint32_t(cycles()-start)<TimeoutCycles) {sawLow=true;done=rd(Ctrl);}
        const uint32_t elapsed=cycles()-start,status=rd(IqStatusReg);
        wr(Ctrl,rd(Ctrl)&~Arm);const uint32_t after=rd(Ctrl);
        result.armed=armed;result.done=done;result.status=status;result.after=after;
        result.cycles=elapsed;result.sawLow=sawLow;
        for(unsigned i=0;i<n;i++) {
          result.changed+=iqStorage.words[i]!=(sentinel^i);
          int16_t a,b;decode(iqStorage.words[i],a,b);result.sumA+=a;result.sumB+=b;
          result.energy+=int32_t(a)*a+int32_t(b)*b;
        }
        for(unsigned i=n;i<MaxWords;i++)result.beyond+=rd(Base+i*4u)!=(sentinel^i);
        for(unsigned i=0;i<GuardWords;i++)result.guards+=iqStorage.guard[i]!=(0xCAFE0000u^sequence^i);
        if(after&Arm) {result.code=IqStatus::DisarmFailed;state.lastError="capture_disarm";}
        else if(!(done&Done)) {result.code=IqStatus::Timeout;state.lastError="capture_timeout";}
        else if(!sawLow) {result.code=IqStatus::StaleDone;state.lastError="capture_stale_done";}
        else if(((status>>16)&0x3FFFu)!=uint32_t(n)+1u||(status&0x3FFFu)!=n) {result.code=IqStatus::CountMismatch;state.lastError="capture_count";}
        else if(result.beyond||result.guards) {result.code=IqStatus::Overrun;state.lastError="capture_overrun";}
        else if(result.changed!=n) {result.code=IqStatus::NotWritten;state.lastError="capture_not_written";}
        else {result.code=IqStatus::Ok;result.valid=true;lastWords=n;state.lastError="none";}
      }
    }
    // Establish the raw-word reference hash while the SDK still cannot run.
    // Later verifyBufferHash calls can then detect a clobber during restore,
    // TCP transmission, yield, or any other Wi-Fi activity.
    if(result.valid) {result.hash=hashWords(lastWords);state.bufferHash=result.hash;}
    const bool restored=restoreRadio();result.radioRestoreOK=restored;
    if(!restored) {result.code=IqStatus::RadioRestore;result.valid=false;state.lastError="radio_restore";}
    }
    const bool gateRestored=WEBSDR_RX_GATE_ENABLE?endRxGate():true;
    if(!profileEntered){state.radioRestored=gateRestored;result.radioRestoreOK=gateRestored;++state.restoreCount;}
    if(!gateRestored)gateRestoreFault();
  }
  state.borrowCycles=cycles()-borrowStart;
  __asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
  lastValid=result.valid&&result.radioRestoreOK;
  if(lastValid&&!verifyBufferHash()) {
    lastValid=false;result.valid=false;result.code=IqStatus::Overrun;
    state.lastError="buffer_changed_on_wifi_return";
  }
  if(!lastValid)lastWords=0;
  state.busy=false;return lastValid;
}

// Compare the observable public SDK context. The caller additionally compares
// boot/association/disconnection/IP-event and WebSocket epochs end to end.
static bool sameSessionContext(bool homeRequired) {
  if(wifi_get_opmode()!=session.mode||wifi_station_get_connect_status()!=STATION_GOT_IP)return false;
  if(homeRequired&&wifi_get_channel()!=session.homeChannel)return false;
  uint8_t own[6];ip_info network={};
  if(!wifi_get_macaddr(STATION_IF,own)||memcmp(own,session.ownMac,6))return false;
  const uint8_t *bssid=WiFi.BSSID();
  if(!bssid||memcmp(bssid,session.bssid,6))return false;
  if(!wifi_get_ip_info(STATION_IF,&network))return false;
  return network.ip.addr==session.ip&&network.netmask.addr==session.netmask&&network.gw.addr==session.gateway;
}

bool beginSession() {
  if(state.busy||session.active)return false;
  if(processorStatus()&0x1Fu) {invalidate(IqStatus::BadContext,"not_main_context");return false;}
  if(!state.ready||radioFault) {invalidate(radioFault?IqStatus::RadioRestore:IqStatus::NotReady,
      radioFault?"previous_restore_failure":"not_ready");return false;}
  if(wifi_get_opmode()!=STATION_MODE||wifi_station_get_connect_status()!=STATION_GOT_IP) {
    invalidate(IqStatus::NotAssociated,"station_not_connected");return false;
  }
  session.homeChannel=wifi_get_channel();session.mode=wifi_get_opmode();
  if(session.homeChannel<1u||session.homeChannel>11u) {invalidate(IqStatus::RadioInit,"home_channel");return false;}
  ip_info network={};const uint8_t *bssid=WiFi.BSSID();
  if(!wifi_get_ip_info(STATION_IF,&network)||!wifi_get_macaddr(STATION_IF,session.ownMac)||!bssid) {
    invalidate(IqStatus::RadioInit,"home_context");return false;
  }
  memcpy(session.bssid,bssid,6);
  session.ip=network.ip.addr;session.netmask=network.netmask.addr;session.gateway=network.gw.addr;
  session.fineDirty=session.fineActive=false;
  session.savedRetuneControl=rd(RetuneControl)&RetuneControlMask;
  state.savedRetuneControl=session.savedRetuneControl;
  state.returnedRetuneControl=session.savedRetuneControl;
#if WEBSDR_ENABLE_FINE_TUNE
  state.nativeOffsetBefore=phy_freq_offset;state.nativeOffsetAfter=phy_freq_offset;
#endif
  session.active=true;state.apChannel=session.homeChannel;
  state.rfRestoreVerified=false;state.retuneRestoreCycles=0;
  state.rxSessionRestored=true;state.expectedHomeRxReopen=false;
  if(!snapshotHomeDivider()) {
    const bool safe=sameSessionContext(true);session.active=false;
    state.rfRestoreVerified=safe;state.radioRestored=safe&&!radioFault;
    invalidate(IqStatus::Busy,"home_pll_not_stable");return false;
  }
  const uint32_t unsupportedBefore=state.rxSessionUnsupported;
  if(!acquireSessionRx()) {
    const char *error=state.lastError;
    const bool gateRestored=sessionRx.active?releaseSessionRx():state.rxSessionRestored;
    const bool safe=gateRestored&&sameSessionContext(true);
    session.active=false;state.rfRestoreVerified=safe;state.radioRestored=safe&&!radioFault;
    if(!safe) {
      ++state.restoreFailures;radioFault=true;state.ready=false;
      invalidate(IqStatus::RadioRestore,"rx_session_acquire_cleanup_failed");
    } else invalidate(state.rxSessionUnsupported!=unsupportedBefore?IqStatus::UnsupportedRetune:IqStatus::Busy,error);
    return false;
  }
  return true;
}

static bool prepareWindow(uint16_t mhz,uint16_t n) {
  if(state.busy)return false;
  if(processorStatus()&0x1Fu) {invalidate(IqStatus::BadContext,"not_main_context");return false;}
  if(!session.active) {invalidate(IqStatus::BadContext,"no_capture_session");return false;}
  if(!state.ready||radioFault) {invalidate(radioFault?IqStatus::RadioRestore:IqStatus::NotReady,
      radioFault?"previous_restore_failure":"not_ready");return false;}
  if(!supportsFrequency(mhz)) {invalidate(IqStatus::UnsupportedRetune,"capture_frequency_step");return false;}
  if(n<2u||n>MaxWords) {invalidate(IqStatus::BadSize,"capture_size");return false;}
  if(!sameSessionContext(false)) {invalidate(IqStatus::NotAssociated,"session_context_changed");return false;}
  const uint8_t target=nearestChannel(mhz);
  const uint16_t baseMHz=uint16_t(2407u+5u*target);
  const int32_t offset=(int32_t(mhz)-baseMHz)*1024;
  state.captureChannel=target;state.pllBaseMHz=baseMHz;state.pllTargetMHz=mhz;
  state.actualCaptureMHz=0;state.offset1024=offset;
  state.logicalChannel=wifi_get_channel();
  state.retuneNeeded=true;
  state.retuneVerified=false;state.retuneCycles=0;state.fineCalibrationDone=false;
  memset(state.fineExpected,0,sizeof(state.fineExpected));memset(state.fineObserved,0,sizeof(state.fineObserved));
  if(!awaitMacIdle(false)) {invalidate(IqStatus::Busy,"mac_busy_before_pll_retune");return false;}
  if(!observeSessionRx(2,true)) {invalidate(IqStatus::UnsupportedRetune,"rx_session_before_pll");return false;}
  const uint8_t xtal=chip6_phy_init_ctrl[1];
  if(xtal>2u) {invalidate(IqStatus::RadioInit,"xtal_selector");return false;}
  state.busy=true;++state.retuneCount;++state.pllProgramCount;const uint32_t start=cycles();
  // The SDK logical channel deliberately stays HOME. Program the native PLL
  // helper for every physical target, including a channel center/offset0.
  session.fineDirty=true;session.fineActive=true;
  set_rf_freq_offset(int(xtal),int(baseMHz),int(offset));
  bool setOK=observeSessionRx(5,false);
  setOK=setOK&&fineReadback(xtal,baseMHz,offset);
  state.retuneCycles=cycles()-start;state.busy=false;
  state.retuneVerified=setOK&&wifi_get_channel()==session.homeChannel&&sameSessionContext(false);
  if(!state.retuneVerified) {++state.pllVerificationFailures;invalidate(IqStatus::RadioInit,"physical_pll_target_not_verified");return false;}
  return true;
}

bool captureWindow(uint16_t mhz,uint16_t n) {
  if(!prepareWindow(mhz,n))return false;
  const bool ok=captureCurrent(mhz,n);
  // The inner profile has returned to the target channel. A session still
  // away from home is not yet a completed return to the AP's Wi-Fi context.
  if(wifi_get_channel()!=session.homeChannel||session.fineActive)state.radioRestored=false;
  return ok;
}

bool probeMacRxGate(uint16_t mhz,uint16_t holdUs) {
  if(!WEBSDR_RX_GATE_ENABLE||holdUs>1000u) {state.lastError="rx_gate_probe_range_or_disabled";return false;}
  if(!prepareWindow(mhz,2))return false;
  state.busy=true;uint32_t ps;
  if(!awaitMacIdle(true,&ps)) {state.busy=false;state.lastError="mac_busy_before_gate_probe";return false;}
  const bool entered=beginRxGate();
  if(entered) {
    const uint32_t start=cycles();
    while(uint32_t(cycles()-start)<160u*holdUs){}
  }
  const bool restored=endRxGate();
  __asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
  ++state.rxGateProbeCount;state.busy=false;
  if(!restored){gateRestoreFault();return false;}
  if(!entered){state.lastError="rx_gate_probe_not_idle";return false;}
  state.lastError="none";
  // Preserve the previous real IqResult/buffer. No capture sequence, valid
  // result, sample count or payload is fabricated by this diagnostic.
  return true;
}

bool endSession() {
  if(!session.active)return false;
  if(state.busy||(processorStatus()&0x1Fu)) {
    state.rfRestoreVerified=false;++state.retuneRestoreFailures;++state.restoreFailures;
    radioFault=true;state.ready=false;state.radioRestored=false;
    lastValid=result.valid=false;lastWords=0;result.radioRestoreOK=false;
    result.code=IqStatus::RadioRestore;state.lastError="invalid_restore_context";
    return false;  // Remain active: a later foreground call may attempt cleanup.
  }
  // Observe only: never wait/yield away from the AP for a queued frame.
  // Software backlog alone does not invalidate a verified return home.
  const bool homeAdmission=macObservedIdle();
  if(!homeAdmission)++state.macHomeBusyObservations;
  state.busy=true;
  const uint32_t start=cycles();
  const bool leaseBeforeHome=observeSessionRx(8,true);
  // Even after a failed window, always attempt to return to the saved home.
  // This is unconditional, including an unchanged logical channel. It is the
  // LAST frequency API operation: the SDK reinstates its own native CFO/AFC.
  // Calling fine(home,0) afterwards would incorrectly erase that correction.
  const bool setOK=wifi_set_channel(session.homeChannel);
  // Native home cleanup is the intentional end of the closed-RX interval.
  // With native bit25 set, this public call legitimately wakes/reopens RX.
  // Do not classify that cleanup transition as a hidden mid-session reopen.
  ++state.rxSessionChecks;state.rxSessionLastStage=9;
  state.rxSessionLastControl=rd(MacRxControl);
  state.expectedHomeRxReopen=(state.rxSessionLastControl&MacRxEnable)!=0;
  if(session.fineDirty)wr(RetuneControl,(rd(RetuneControl)&~RetuneControlMask)|session.savedRetuneControl);
  state.returnedRetuneControl=rd(RetuneControl)&RetuneControlMask;
#if WEBSDR_ENABLE_FINE_TUNE
  state.nativeOffsetAfter=phy_freq_offset;
#endif
  const bool physicalHome=verifyHomeDivider();
  const bool gateRestored=releaseSessionRx();
  state.retuneRestoreCycles=cycles()-start;
  const bool leaseOK=leaseBeforeHome&&!sessionRx.broken;
  const bool restored=setOK&&physicalHome&&sameSessionContext(true)&&gateRestored&&
      (!session.fineDirty||state.returnedRetuneControl==session.savedRetuneControl);
  session.fineActive=session.fineDirty=false;
  session.active=false;state.busy=false;state.rfRestoreVerified=restored;
  if(!restored) {
    ++state.retuneRestoreFailures;++state.restoreFailures;
    radioFault=true;state.ready=false;state.radioRestored=false;
    lastValid=result.valid=false;lastWords=0;result.radioRestoreOK=false;
    result.code=IqStatus::RadioRestore;state.lastError="sdk_home_restore_failed";
    return false;
  }
  if(!leaseOK) {
    lastValid=result.valid=false;lastWords=0;result.code=radioFault?IqStatus::RadioRestore:IqStatus::RadioInit;
    state.lastError="rx_session_lease_violated";result.radioRestoreOK=!radioFault;state.radioRestored=!radioFault;
    return false;
  }
  result.radioRestoreOK=result.radioRestoreOK&&!radioFault;
  state.radioRestored=result.radioRestoreOK;
  if(lastValid&&!verifyBufferHash()) {
    lastValid=result.valid=false;lastWords=0;result.code=IqStatus::Overrun;
    state.lastError="buffer_changed_on_home_return";
    return false;
  }
  return !radioFault;
}

bool capture(uint16_t n) {
  if(!beginSession())return false;
  const bool captured=captureWindow(state.requestedMHz,n);
  const bool restored=endSession();  // Intentionally not short-circuited.
  return captured&&restored&&lastValid;
}
bool verifyBufferHash() {
  ++state.bufferHashChecks;
  if(!lastValid||hashWords(lastWords)!=state.bufferHash) {++state.bufferHashFailures;return false;}
  return true;
}
}


// ===== WifiCredentials.h =====
// Private device configuration. Do not publish this file or configured images.
// ===== BEGIN integrated wifi_credentials.h =====
#define SDR_WIFI_SSID "TESTWIFI"
#define SDR_WIFI_PASSWORD "PASSWORD"

// ===== END integrated wifi_credentials.h =====



// ===== DirectSession.h =====
#include <Arduino.h>
#include <ESP8266WiFi.h>






static NetworkWebSocketLink IQSocket(81);

namespace DirectSession {
static WiFiEventHandler onConnect,onDisconnect,onIp;
static uint32_t boot,associations,disconnects,gotIp,nextConnectMs,lastReconnectMs;
static uint32_t transactions,transactionFailures,captures,captureFailures,pmFailures;
static uint32_t pmEnterUs,pmExitUs,captureWindowUs,lastCommandUs,lastOutputUs;
static uint32_t commandStartUs,outputStartUs,beforeEpoch;
static uint32_t beforeRestoreFailures,beforeBufferFailures,beforeTxErrors;
static uint8_t bssid[6];
static bool inTransaction,latchedFault,configured;
static bool captureValid;
static uint8_t captureCode;
static WifiContextSnapshot::Value before;

static bool ready() {
  return !latchedFault&&WiFi.status()==WL_CONNECTED&&IQSocket.connected();
}
static uint16_t centerMHz() {return uint16_t(2407u+5u*wifi_get_channel());}
static void begin() {
  // The application has no UART protocol, logging, or IQ output.
  system_set_os_print(0);
  boot=os_random();
  WiFi.persistent(false);
  onConnect=WiFi.onStationModeConnected([](const WiFiEventStationModeConnected&e){
    ++associations;memcpy(bssid,e.bssid,6);configured=false;
  });
  onDisconnect=WiFi.onStationModeDisconnected([](const WiFiEventStationModeDisconnected&){
    ++disconnects;configured=false;if(inTransaction)latchedFault=true;
  });
  onIp=WiFi.onStationModeGotIP([](const WiFiEventStationModeGotIP&){++gotIp;});
  WiFi.mode(WIFI_STA);
  WiFi.setAutoConnect(false);WiFi.setAutoReconnect(false);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  WiFi.config(IPAddress(192,168,1,38),IPAddress(0,0,0,0),IPAddress(255,255,255,0));
  // Exact SSID is used even when beacon SSID advertisement is disabled.
  WiFi.begin(SDR_WIFI_SSID,SDR_WIFI_PASSWORD,0,nullptr,true);
  wifi_station_set_auto_connect(0);WiFi.setAutoReconnect(false);
  IQSocket.begin();IQSocket.setNoDelay(true);
}
static void poll() {
  IQSocket.poll();
  if(inTransaction||latchedFault)return;
  const uint32_t now=millis();
  if(int32_t(now-nextConnectMs)<0)return;
  nextConnectMs=now+1000;
  if(WiFi.status()!=WL_CONNECTED&&uint32_t(now-lastReconnectMs)>15000) {
    lastReconnectMs=now;wifi_station_connect();
  }
}
static bool powerSave(bool enabled) {
  if(enabled?!ready():WiFi.status()!=WL_CONNECTED)return false;
  const uint32_t started=micros();
  const bool ok=PowerSaveControl::send(enabled,bssid);
  if(enabled)pmEnterUs=micros()-started;else pmExitUs=micros()-started;
  if(!ok)++pmFailures;
  return ok;
}
static bool beginTransaction() {
  if(!ready()||inTransaction)return false;
  before=WifiContextSnapshot::read(bssid,boot,associations,disconnects,gotIp);
  if(!before.valid)return false;
  beforeEpoch=IQSocket.epoch();inTransaction=true;++transactions;
  beforeRestoreFailures=WebSdrCapture::status().restoreFailures;
  beforeBufferFailures=WebSdrCapture::status().bufferHashFailures;
  beforeTxErrors=IQSocket.stats().txErrors;
  commandStartUs=micros();return true;
}
static bool finishCommand(bool transaction,bool checkBuffer) {
  outputStartUs=micros();
  // All WS bytes are copied into the SDK's TCP buffers before returning.
  // The next browser request provides application backpressure. Waiting for
  // the last TCP ACK here would add latency without proving browser CRC.
  const bool drained=IQSocket.endPacket(3000);
  lastOutputUs=micros()-outputStartUs;
  if(!transaction)return drained;
  const bool bufferOK=!checkBuffer||WebSdrCapture::verifyBufferHash();
  const bool sameWifi=WifiContextSnapshot::sameConnection(before,
    WifiContextSnapshot::read(bssid,boot,associations,disconnects,gotIp));
  const bool radioOK=sameWifi&&bufferOK&&
    WebSdrCapture::status().restoreFailures==beforeRestoreFailures&&
    WebSdrCapture::status().bufferHashFailures==beforeBufferFailures;
  const bool ok=radioOK&&drained&&!latchedFault&&IQSocket.connected()&&
    beforeEpoch==IQSocket.epoch()&&IQSocket.stats().txErrors==beforeTxErrors;
  lastCommandUs=micros()-commandStartUs;
  if(!ok)++transactionFailures;
  if(!radioOK)latchedFault=true;
  inTransaction=false;return ok;
}
static void printNet() {
  const String ip=WiFi.localIP().toString(),mask=WiFi.subnetMask().toString();
  const String gw=uint32_t(WiFi.gatewayIP())?WiFi.gatewayIP().toString():String("0.0.0.0");
  IQSocket.printf("NET {\"ip\":\"%s\",\"netmask\":\"%s\",\"gateway\":\"%s\",\"channel\":%u,\"frequencyMHz\":%u,\"transport\":\"WS\",\"captureFrequencyMHz\":%u,\"tuneStepMHz\":%u,\"boot\":%lu,\"assoc\":%lu,\"disconnect\":%lu,\"gotIp\":%lu,\"wsEpoch\":%lu,\"fault\":%u}\n",
    ip.c_str(),mask.c_str(),gw.c_str(),unsigned(wifi_get_channel()),unsigned(centerMHz()),unsigned(WebSdrCapture::status().requestedMHz),unsigned(WebSdrCapture::tuneStepMHz()),boot,
    associations,disconnects,gotIp,IQSocket.epoch(),unsigned(latchedFault));
}
static void printPerformance() {
  const auto &c=WebSdrCapture::status();const auto &r=WebSdrCapture::lastResult();
  const auto pm=Esp8266PmNull::snapshot();const auto &p=PowerSaveControl::stats();const auto &s=IQSocket.stats();
  IQSocket.printf("PERF {\"boot\":%lu,\"assoc\":%lu,\"disconnect\":%lu,\"gotIp\":%lu,\"wsEpoch\":%lu,\"transactions\":%lu,\"transactionFailures\":%lu,\"captures\":%lu,\"captureFailures\":%lu,\"valid\":%u,\"code\":%u,\"words\":%u,\"changed\":%lu,\"beyond\":%lu,\"guards\":%lu,\"captureCrc\":%lu,",
    boot,associations,disconnects,gotIp,IQSocket.epoch(),transactions,transactionFailures,captures,
    captureFailures,unsigned(captureValid),unsigned(captureCode),unsigned(captureValid?WebSdrCapture::count():0),
    r.changed,r.beyond,r.guards,r.hash);
  IQSocket.printf("\"captureUs\":%lu,\"borrowUs\":%lu,\"pmEnterUs\":%lu,\"pmExitUs\":%lu,\"captureWindowUs\":%lu,\"lastCommandUs\":%lu,\"lastDrainUs\":%lu,\"restoreFailures\":%lu,\"bufferChecks\":%lu,\"bufferFailures\":%lu,\"pmSubmitted\":%lu,\"pmCompleted\":%lu,\"pmFailures\":%lu,",
    (r.cycles+159u)/160u,(c.borrowCycles+159u)/160u,pmEnterUs,pmExitUs,captureWindowUs,
    lastCommandUs,lastOutputUs,c.restoreFailures,c.bufferHashChecks,c.bufferHashFailures,
    pm.submitted,pm.completed,pmFailures);
  IQSocket.printf("\"pmAttempts\":%lu,\"pmRetries\":%lu,\"pmTxErrors\":%lu,\"pmQueueErrors\":%lu,\"pmTimeouts\":%lu,\"pmLastQueueRc\":%d,\"pmLastTxStatus\":%u,",
    p.attempts,p.retries,p.txErrors,p.queueErrors,p.timeouts,p.lastQueueRc,unsigned(p.lastTxStatus));
  IQSocket.printf("\"captureFrequencyMHz\":%u,\"captureChannel\":%u,\"apChannel\":%u,\"retuneVerified\":%u,\"rfRestoreVerified\":%u,\"retuneCount\":%lu,\"retuneRestoreFailures\":%lu,\"retuneUs\":%lu,\"retuneRestoreUs\":%lu,",
    unsigned(c.actualCaptureMHz),unsigned(c.captureChannel),unsigned(c.apChannel),unsigned(c.retuneVerified),
    unsigned(c.rfRestoreVerified),c.retuneCount,c.retuneRestoreFailures,(c.retuneCycles+159u)/160u,(c.retuneRestoreCycles+159u)/160u);
  IQSocket.printf("\"fineOffsetQ10\":%d,\"fineCalibrationDone\":%u,\"fineExpected\":[%u,%u,%u],\"fineObserved\":[%u,%u,%u],\"nativeOffsetBefore\":%d,\"nativeOffsetAfter\":%d,\"savedRetuneControl\":%lu,\"returnedRetuneControl\":%lu,",
    int(c.offset1024),unsigned(c.fineCalibrationDone),unsigned(c.fineExpected[0]),unsigned(c.fineExpected[1]),unsigned(c.fineExpected[2]),
    unsigned(c.fineObserved[0]),unsigned(c.fineObserved[1]),unsigned(c.fineObserved[2]),int(c.nativeOffsetBefore),int(c.nativeOffsetAfter),
    c.savedRetuneControl,c.returnedRetuneControl);
  IQSocket.printf("\"macAdmissionChecks\":%lu,\"macBusyRetries\":%lu,\"macWaitUs\":%lu,\"macMaxWaitUs\":%lu,\"macAdmissionTimeouts\":%lu,\"macLastIdleMask\":%u,\"macLastActive\":%u,\"macHardware410\":%u,\"macHardware1D0\":%u,",
    c.macAdmissionChecks,c.macBusyRetries,(c.macWaitCycles+159u)/160u,(c.macMaxWaitCycles+159u)/160u,
    c.macAdmissionTimeouts,unsigned(c.macLastIdleMask),unsigned(c.macLastActive),unsigned(c.macHardware410),unsigned(c.macHardware1D0));
  IQSocket.printf("\"macImmediateBusyAborts\":%lu,\"macHomeBusyObservations\":%lu,\"rxGateCount\":%lu,\"rxGateRestoreCount\":%lu,\"rxGateFailures\":%lu,\"rxGateTimeouts\":%lu,\"rxGateRestoreFailures\":%lu,",
    c.macImmediateBusyAborts,c.macHomeBusyObservations,c.rxGateCount,c.rxGateRestoreCount,c.rxGateFailures,c.rxGateTimeouts,c.rxGateRestoreFailures);
  IQSocket.printf("\"rxGateWaitUs\":%lu,\"rxGateMaxWaitUs\":%lu,\"rxGateLastLoanUs\":%lu,\"rxGateProbeCount\":%lu,\"rxGateControlBefore\":%lu,\"rxGateControlGated\":%lu,\"rxGateControlReturned\":%lu,",
    (c.rxGateWaitCycles+159u)/160u,(c.rxGateMaxWaitCycles+159u)/160u,(c.rxGateLastLoanCycles+159u)/160u,c.rxGateProbeCount,
    c.rxGateControlBefore,c.rxGateControlGated,c.rxGateControlReturned);
  IQSocket.printf("\"rxGateStopBefore\":%lu,\"rxGateStopReturned\":%lu,\"rxGateHardware410\":%u,\"rxGateHardware1D0\":%u,\"rxGateRestored\":%u,",
    c.rxGateStopBefore,c.rxGateStopReturned,unsigned(c.rxGateHardware410),unsigned(c.rxGateHardware1D0),unsigned(c.rxGateRestored));
  IQSocket.printf("\"rxSessionLoans\":%lu,\"rxSessionRestores\":%lu,\"rxSessionChecks\":%lu,\"rxSessionReenabled\":%lu,\"rxSessionUnsupported\":%lu,\"rxSessionAcquireTimeouts\":%lu,\"rxSessionRestoreFailures\":%lu,",
    c.rxSessionLoans,c.rxSessionRestores,c.rxSessionChecks,c.rxSessionReenabled,c.rxSessionUnsupported,c.rxSessionAcquireTimeouts,c.rxSessionRestoreFailures);
  IQSocket.printf("\"rxSessionControlBefore\":%lu,\"rxSessionControlDisabled\":%lu,\"rxSessionControlReturned\":%lu,\"rxSessionLastControl\":%lu,\"rxSessionSleepFlags\":%lu,\"rxSessionLastStage\":%lu,\"rxSessionActive\":%u,\"rxSessionRestored\":%u,",
    c.rxSessionControlBefore,c.rxSessionControlDisabled,c.rxSessionControlReturned,c.rxSessionLastControl,
    c.rxSessionSleepFlags,c.rxSessionLastStage,unsigned(c.rxSessionActive),unsigned(c.rxSessionRestored));
  IQSocket.printf("\"rfTuneBackend\":\"native-pll\",\"pllProgramCount\":%lu,\"pllVerificationFailures\":%lu,\"pllLogicalChannelFailures\":%lu,\"pllBaseMHz\":%u,\"logicalChannel\":%u,",
    c.pllProgramCount,c.pllVerificationFailures,c.pllLogicalChannelFailures,unsigned(c.pllBaseMHz),unsigned(c.logicalChannel));
  IQSocket.printf("\"homeBefore\":[%u,%u,%u],\"homeExpected\":[%u,%u,%u],\"homeObserved\":[%u,%u,%u],\"homeCalibrationDone\":%u,\"homeReturnVerified\":%u,\"homeOracleUsed\":%u,\"expectedHomeRxReopen\":%u,",
    unsigned(c.homeBefore[0]),unsigned(c.homeBefore[1]),unsigned(c.homeBefore[2]),unsigned(c.homeExpected[0]),unsigned(c.homeExpected[1]),unsigned(c.homeExpected[2]),
    unsigned(c.homeObserved[0]),unsigned(c.homeObserved[1]),unsigned(c.homeObserved[2]),unsigned(c.homeCalibrationDone),unsigned(c.homeReturnVerified),unsigned(c.homeOracleUsed),unsigned(c.expectedHomeRxReopen));
  IQSocket.printf("\"pmBackoffCount\":%lu,\"pmBackoffUs\":%lu,",p.backoffCount,p.backoffTotalUs);
  IQSocket.printf("\"txBytes\":%lu,\"rxBytes\":%lu,\"txErrors\":%lu,\"rxOverflow\":%lu,\"drainTimeouts\":%lu,\"framesTx\":%lu,\"heap\":%u,\"fault\":%u,\"uartIqBytes\":0,",
    s.txBytes,s.rxBytes,s.txErrors,s.rxOverflow,s.drainTimeouts,s.framesTx,
    ESP.getFreeHeap(),unsigned(latchedFault));
  IQSocket.printf("\"tcpMss\":%u,\"txBufferBytes\":%u,\"writeTimeouts\":%lu,\"protocolErrors\":%lu,\"handshakeErrors\":%lu,\"rejectedClients\":%lu,\"socketDisconnects\":%lu,", unsigned(TCP_MSS),unsigned(NetworkWebSocketLink::TxCapacity+NetworkWebSocketLink::TxPrefix),s.writeTimeouts,s.protocolErrors,s.handshakeErrors,s.rejectedClients,s.disconnects);
  IQSocket.printf("\"tcpAckWait\":0,\"endPackets\":%lu,\"acceptedBytes\":%lu,\"wireTxBytes\":%lu,\"droppedTxBytes\":%lu,\"stackFree\":%u,\"coreError\":\"%s\"}\n",
    s.endPackets,s.acceptedBytes,s.wireTxBytes,s.droppedTxBytes,
    ESP.getFreeContStack(),c.lastError?c.lastError:"none");
}
}


// ===== WebPage.h =====
#include <Arduino.h>
static const uint8_t sdrPageGzip[] PROGMEM = {
  0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0x0a,0xad,0x7d,0xdb,0x72,0xdb,0xb8,0x96,0xe8,0xbb,0xbf,
  0x82,0x56,0xba,0x4d,0xf1,0x98,0xa2,0x25,0xf9,0x16,0x93,0xa6,0x3c,0xe9,0x5c,0x76,0xe7,0x4c,0xe7,0x52,
  0x89,0x33,0xdd,0x55,0xa9,0xd4,0x14,0x4c,0x42,0x16,0xb7,0x29,0x92,0x9b,0x84,0x6c,0xa9,0x65,0x55,0xed,
  0xf7,0x79,0x38,0x0f,0x33,0x55,0xfb,0x0f,0xe6,0x17,0xce,0xfb,0xf9,0x94,0xfe,0x92,0x53,0x6b,0xe1,0x42,
  0x80,0xa4,0x6c,0x67,0xf7,0xe4,0x21,0x11,0x41,0x60,0x61,0x61,0x61,0xdd,0xb1,0xc0,0x9c,0xef,0xc6,0x79,
  0xc4,0x56,0x05,0xb5,0x66,0x6c,0x9e,0x4e,0x76,0xce,0xe1,0x1f,0x2b,0x25,0xd9,0x75,0xd8,0xa3,0x59,0x0f,
  0x1a,0x28,0x89,0x27,0x3b,0xe7,0x73,0xca,0x88,0x15,0xcd,0x48,0x59,0x51,0x16,0xf6,0x16,0x6c,0x3a,0x78,
  0xde,0x93,0xcd,0x19,0x99,0xd3,0xb0,0x77,0x9b,0xd0,0xbb,0x22,0x2f,0x59,0xcf,0x8a,0xf2,0x8c,0xd1,0x8c,
  0x85,0xbd,0xbb,0x24,0x66,0xb3,0x30,0xa6,0xb7,0x49,0x44,0x07,0xf8,0xe0,0x26,0x59,0xc2,0x12,0x92,0x0e,
  0xaa,0x88,0xa4,0x34,0x1c,0x29,0x18,0x33,0xc6,0x8a,0x01,0xfd,0xdb,0x22,0xb9,0x0d,0x7b,0x2f,0xf9,0xf8,
  0xc1,0x67,0x1a,0x2d,0xca,0x84,0xad,0x06,0x1f,0xf3,0x34,0x89,0x56,0x1a,0xe0,0x98,0x4e,0xc9,0x22,0x65,
  0x83,0xaa,0x8c,0x2c,0x3b,0xcb,0x33,0x6a,0x07,0x56,0x15,0x95,0x49,0x21,0x9a,0x16,0x59,0x45,0xa6,0x74,
  0x90,0x64,0x69,0xc2,0xdf,0xb1,0x55,0x4a,0xbb,0x5f,0x45,0x79,0x96,0xd1,0x48,0x8c,0xab,0x68,0x3a,0xb5,
  0xad,0xbb,0xca,0x0f,0xac,0x64,0x7e,0x8d,0x6d,0x31,0x61,0xc4,0x0f,0xac,0x2b,0x52,0xd1,0xc1,0xa2,0x4c,
  0xd4,0x74,0xd3,0xbc,0x9c,0x0f,0x48,0xc4,0x92,0x3c,0x13,0x6d,0xb0,0x16,0x96,0xb0,0x94,0x4e,0x5e,0x7f,
  0xfe,0xf8,0x53,0xfe,0x61,0xfe,0x7c,0x7c,0x72,0x72,0xf9,0x9b,0xf5,0xff,0xfe,0xaf,0xf5,0xe9,0x8d,0xc5,
  0x4a,0x92,0x55,0xf3,0x84,0x31,0x5a,0x9e,0x1f,0xf0,0x6e,0x3b,0xe7,0x69,0x92,0xdd,0x58,0x25,0x4d,0xc3,
  0x5e,0x12,0xe5,0x59,0xcf,0x9a,0x95,0x74,0x1a,0xf6,0x70,0x4a,0x17,0xc0,0x21,0xde,0x93,0x1d,0xbf,0xcc,
  0x73,0xb6,0x8e,0xf2,0x34,0x2f,0x07,0x55,0x34,0xa3,0x73,0xea,0xc7,0xa4,0xbc,0x09,0x06,0x83,0xab,0x6b,
  0xff,0xd9,0x68,0x34,0x3a,0x1b,0xd1,0x60,0x30,0x88,0x48,0x19,0xfb,0xcf,0x46,0xcf,0xc7,0xe3,0xf1,0x49,
  0x30,0x18,0x14,0x24,0xa3,0xa9,0xff,0x6c,0x7c,0x76,0x38,0x3a,0x3c,0x86,0xbe,0x79,0x19,0xd3,0xd2,0x7f,
  0x76,0x48,0x8e,0x4e,0x8f,0xe2,0x60,0x30,0x60,0x74,0xc9,0xfc,0x67,0xd1,0x28,0x3e,0xa6,0xc3,0x60,0x30,
  0x98,0x2f,0x18,0x8d,0xfd,0x67,0x67,0x23,0x72,0x76,0x75,0x14,0x0c,0x06,0xd7,0x25,0xa5,0x99,0xff,0xec,
  0xf0,0x94,0x3e,0x3f,0x3d,0x0b,0x06,0x03,0x32,0xbf,0x82,0xe1,0xd3,0x69,0x74,0x74,0x04,0xd3,0x95,0xd0,
  0x7b,0x3a,0x3d,0x3d,0x3c,0x3d,0x04,0xe8,0xe9,0x82,0xfa,0xcf,0x4e,0x86,0xd1,0xc9,0xf4,0x78,0xb3,0xf3,
  0xbf,0xd6,0x57,0xf9,0x72,0x50,0x25,0xbf,0x27,0xd9,0xb5,0xcf,0x27,0x1e,0x5c,0xe5,0xcb,0xcd,0x55,0x1e,
  0xaf,0xd6,0x73,0x52,0x5e,0x27,0x99,0x3f,0x0c,0xae,0x48,0x74,0x73,0x5d,0xe6,0x8b,0x2c,0xf6,0x6f,0x49,
  0xd9,0x87,0xe5,0x38,0x01,0x2e,0x53,0x3c,0x03,0x86,0x4e,0x30,0xcd,0x33,0xe6,0x8f,0x8e,0x8a,0xe5,0xc1,
  0xc8,0x3b,0x3a,0xb6,0x5e,0x94,0x09,0x49,0xdd,0x8a,0x64,0xd5,0xa0,0xa2,0x65,0x32,0xdd,0x5c,0x2d,0x18,
  0xcb,0x33,0x37,0xc9,0x8a,0x05,0x73,0x2b,0x9a,0xd2,0x88,0xad,0x71,0x4c,0x92,0xcd,0x68,0x99,0x30,0xd1,
  0x61,0x3d,0x4f,0xb2,0xc1,0x8c,0x26,0xd7,0x33,0xe6,0x1f,0x8d,0x8b,0x65,0x20,0x08,0x32,0x2a,0x96,0x56,
  0x95,0xa7,0x49,0x6c,0x09,0x24,0xb0,0xd9,0x11,0xaf,0x07,0x25,0x89,0x93,0x45,0xe5,0x9f,0x14,0xcb,0xa0,
  0x20,0x71,0x0c,0x0b,0x3a,0x2b,0x96,0x16,0xe0,0xd3,0x5e,0x00,0xd2,0x5c,0xae,0xe1,0x19,0x3d,0x9e,0x8e,
  0xa7,0xa7,0x41,0xb4,0x28,0xab,0xbc,0xf4,0x8b,0x3c,0xc9,0x18,0x2d,0x05,0x36,0xfe,0x2c,0xbf,0xa5,0xa5,
  0x9f,0xe5,0xac,0xef,0xc7,0x49,0x45,0xae,0x52,0x1a,0x3b,0x6b,0x31,0xa7,0x4e,0x03,0xdc,0x06,0x47,0x8e,
  0x92,0x5d,0xd7,0x02,0xa8,0x90,0x84,0x20,0x2f,0x48,0x94,0xb0,0x95,0xef,0x1d,0x1d,0xcb,0xae,0xd3,0x3c,
  0x5a,0x54,0x83,0xdb,0xa4,0x4a,0xae,0x52,0xca,0xa9,0x63,0xb6,0xad,0xf3,0x05,0x03,0x29,0xf0,0xc7,0x4d,
  0x0a,0xa4,0x0b,0xea,0x04,0xe2,0xed,0x20,0x9f,0x4e,0x2b,0xca,0xfc,0xc3,0x62,0x29,0x20,0x7b,0x45,0x99,
  0xcc,0x49,0xb9,0x5a,0x6b,0xcb,0x7f,0x36,0x22,0xc7,0xa7,0x87,0xa7,0x81,0xb1,0x80,0x67,0x87,0x87,0x67,
  0xa3,0x63,0xa2,0xc8,0x31,0x9d,0x4e,0xa7,0x47,0x12,0x48,0xc5,0xf2,0xc2,0x5c,0xef,0xb3,0xb3,0xf1,0xf1,
  0xe8,0x78,0xa4,0x53,0xf5,0xd9,0xd1,0xd5,0xf8,0x6c,0x7c,0x25,0x21,0x4c,0xa7,0xf4,0x90,0x1e,0xea,0x10,
  0x38,0x19,0xbb,0xe8,0x56,0xd2,0xd8,0xd9,0x80,0xf6,0xa2,0xe5,0x3a,0x4e,0xaa,0x22,0x25,0x2b,0x7f,0x9a,
  0xd2,0x65,0x40,0xd2,0xe4,0x3a,0x1b,0x24,0x8c,0xce,0x2b,0x3f,0xa2,0xb0,0x25,0xc1,0x5f,0x17,0x15,0x4b,
  0xa6,0xab,0x81,0x50,0x30,0x7e,0x55,0x90,0x88,0x0e,0xae,0x28,0xbb,0xa3,0x34,0x53,0xdb,0x3e,0x3a,0x2e,
  0x96,0xd6,0xb8,0xe6,0x9c,0xc1,0x55,0xce,0x58,0x3e,0xdf,0xca,0x40,0xd7,0xa4,0xc0,0x31,0x9b,0xd9,0xa8,
  0xe6,0x79,0x60,0x4c,0x10,0x0c,0xea,0x8f,0x8f,0x8b,0xa5,0x78,0x04,0x31,0xf7,0x13,0x46,0xd2,0x24,0xe2,
  0x2d,0x77,0x9c,0x4d,0xcf,0x86,0xc3,0x20,0xa5,0xa0,0x33,0x06,0x80,0x12,0x20,0x31,0x18,0x15,0x4b,0x45,
  0xd0,0x78,0x3a,0x9d,0x1e,0x06,0x77,0xb3,0x84,0x51,0xec,0x40,0xfd,0x2c,0xbf,0x2b,0x49,0xb1,0x99,0x8d,
  0x2c,0xef,0x2a,0xcf,0xe7,0xeb,0x0e,0x4e,0x82,0x77,0xd9,0x02,0x84,0x79,0xad,0x21,0x33,0xac,0xc1,0x9e,
  0x10,0x7a,0x45,0x68,0x6b,0x62,0xef,0x14,0x97,0x62,0x79,0x6c,0xd9,0x3d,0x90,0xcf,0x82,0x6a,0xc2,0x09,
  0xf8,0x82,0x07,0x29,0x9d,0x32,0xe0,0xaf,0x26,0xb4,0xa1,0xd8,0x1a,0xab,0x90,0xa4,0x39,0x2c,0x96,0xd6,
  0xd0,0x1a,0x1a,0xb0,0x50,0x25,0x39,0x1a,0xcd,0x46,0xe3,0x62,0xb9,0xf1,0xae,0x48,0x7c,0x4d,0xd7,0xdf,
  0x25,0xbe,0x87,0x43,0x4d,0x7e,0x4f,0x41,0x7e,0x01,0x29,0xc9,0x17,0xdc,0x1a,0x0c,0xb6,0xb1,0x07,0x6c,
  0xe4,0xf3,0x62,0xd9,0x41,0xe8,0x16,0x6a,0x71,0xce,0xd6,0x68,0xe9,0x60,0x92,0x40,0x68,0x9b,0xd3,0xf6,
  0x54,0x57,0x69,0x1e,0xdd,0x18,0x9c,0x7e,0x72,0x75,0x7a,0xf5,0xfc,0xb0,0x81,0xf6,0xf1,0xf0,0x47,0xb1,
  0x5c,0x4f,0x18,0x2a,0x1a,0x5b,0x38,0x49,0x4b,0xf5,0x88,0xdd,0x15,0xbd,0x2b,0x46,0x52,0xba,0xa5,0x27,
  0xdf,0xa1,0x8d,0x97,0x92,0x55,0xbe,0x60,0x4a,0x38,0xae,0xcb,0x24,0x0e,0xe0,0xaf,0x01,0xa3,0xf3,0x22,
  0x25,0x8c,0x82,0x3c,0x2d,0xe6,0x59,0xe5,0x8f,0xcf,0x8e,0x8a,0xa5,0x35,0x4f,0xb2,0x39,0x59,0xf6,0x87,
  0xee,0x68,0x2a,0xb9,0xfb,0xb9,0x46,0x55,0x7c,0x98,0x93,0x25,0xb7,0xf4,0xfe,0xe8,0x78,0x38,0xc4,0x06,
  0xdc,0x5d,0xb2,0x60,0xf9,0x86,0x54,0x49,0x4c,0x5d,0x0f,0xec,0xd4,0xa3,0xbb,0xd7,0x44,0x1a,0x06,0x35,
  0x37,0xf5,0x79,0xb1,0xe4,0x30,0xd7,0x06,0x0e,0x7c,0x07,0xc1,0x96,0xfb,0x15,0x23,0x25,0xdb,0xcc,0xc6,
  0x1a,0xc3,0xa2,0xe2,0x96,0xe2,0x68,0x0d,0xad,0xd1,0x89,0x14,0x43,0x21,0x74,0x27,0x43,0xc9,0x84,0xcf,
  0xae,0x8e,0xa3,0x28,0x26,0x1b,0xa0,0x3d,0x2b,0xf3,0xb4,0x6a,0xd0,0x0a,0x28,0x30,0x84,0x5d,0x97,0xef,
  0x2d,0x8f,0xab,0xa6,0x8e,0x8e,0x80,0xab,0x37,0x4d,0x68,0x1a,0xb7,0xdf,0x1d,0x2b,0x8c,0x06,0xa0,0xd2,
  0x00,0x43,0xd1,0xd7,0x4a,0xc9,0x15,0x4d,0x5d,0xaf,0x24,0xd9,0x35,0x1d,0xe0,0x83,0xbe,0x14,0xd0,0xc9,
  0xde,0x2c,0xc9,0x98,0xde,0x38,0x6a,0x08,0xa4,0x10,0x22,0xb1,0xe4,0x23,0x2e,0x66,0x1b,0x0f,0x0d,0xc2,
  0x60,0x91,0x25,0xec,0x51,0xf5,0xa8,0xf0,0xaf,0xc7,0x58,0xf8,0x13,0x4d,0x2a,0xdf,0xee,0x61,0x00,0xa3,
  0xfd,0x51,0x20,0x76,0x7f,0x08,0x9c,0x8b,0xd0,0x4d,0x11,0xe9,0x44,0x4d,0x41,0x01,0x31,0xdd,0x70,0x13,
  0xce,0x2d,0xd6,0x57,0x70,0x4e,0x43,0xae,0xae,0xbe,0xad,0x0d,0x03,0x3c,0x34,0x0d,0xf0,0xb3,0xd1,0x10,
  0xfd,0x20,0xa9,0x1b,0xc7,0x94,0x4e,0x8f,0xbe,0xcf,0xc6,0xe3,0x3e,0x68,0x4e,0x02,0x20,0xa3,0x61,0x81,
  0x9b,0xf0,0x6d,0x5d,0x2f,0x30,0x20,0x11,0x50,0xa8,0xc3,0x5c,0x4b,0x6a,0x9f,0x00,0xb5,0x37,0x62,0xfb,
  0x40,0xe3,0xfd,0x49,0x53,0x84,0x2c,0x87,0x8a,0xa6,0x06,0x69,0xe5,0x0b,0x06,0x7b,0x81,0x74,0xbe,0x25,
  0x65,0x42,0x32,0x36,0xc8,0x16,0x73,0x5a,0x26,0x91,0xcf,0xc8,0xd5,0x22,0x25,0x25,0x3c,0x57,0x26,0x69,
  0x36,0x1e,0xbb,0xcb,0x07,0xb8,0xbc,0xea,0x29,0x3a,0xc0,0x90,0x7e,0xeb,0x14,0xb6,0x52,0x62,0xd3,0xb1,
  0x0e,0x1d,0xba,0xd5,0xb1,0x93,0x3a,0x97,0x54,0xb4,0x20,0x25,0x61,0x79,0xb9,0x16,0x84,0x1f,0x75,0xb9,
  0x56,0x72,0xcb,0x04,0x65,0x41,0xd2,0xad,0xe1,0xe6,0x19,0x29,0x8a,0x74,0xa5,0xef,0x89,0x2e,0x48,0x60,
  0xb1,0xbc,0x39,0xad,0x2a,0x72,0x4d,0xa5,0x9d,0x19,0x3d,0xd9,0xd0,0xe8,0xbc,0x70,0x08,0xbc,0x01,0xae,
  0xc6,0x34,0xcd,0xef,0x06,0xa0,0xfa,0x7d,0x92,0xad,0xee,0x66,0xb4,0xa4,0x6a,0x06,0x8f,0x96,0x65,0x5e,
  0xae,0x5b,0x4e,0x88,0x7a,0x7f,0x9d,0xe7,0x71,0x97,0x45,0x9e,0x93,0x24,0xeb,0x50,0x2d,0xb5,0x2e,0x53,
  0xcc,0x00,0xea,0x4c,0x13,0x97,0xe1,0x86,0x2b,0x53,0x5d,0xfd,0x59,0x63,0xae,0x92,0x48,0x19,0xff,0x8f,
  0x71,0x9c,0xa6,0xa0,0xa4,0xcf,0x73,0x62,0x4c,0x62,0xcd,0xc6,0xca,0xc5,0xd9,0x80,0xf1,0x61,0xf4,0x49,
  0x5a,0x85,0xf3,0x32,0xf6,0x1f,0x40,0x08,0xf4,0xdd,0xc8,0x8a,0x66,0x4e,0x8e,0xa3,0xa3,0xda,0xe6,0xe2,
  0x6f,0x54,0x49,0x10,0x9c,0x7d,0xa7,0x1e,0x18,0xfe,0x18,0x3c,0xe0,0xe1,0x70,0x66,0xd1,0xd1,0xf6,0x20,
  0x10,0xbc,0xa5,0x1d,0x7b,0xdb,0x74,0x88,0xc9,0xf3,0xf8,0xf8,0xd4,0x18,0x8a,0xfe,0x7b,0x8b,0x69,0x82,
  0x2e,0xcf,0x58,0x8e,0xc3,0xf0,0x51,0xf7,0xc1,0xc6,0xdb,0x4d,0x98,0x14,0x76,0x3e,0x32,0xcb,0x19,0x7d,
  0x8a,0x42,0xae,0x65,0x88,0x2b,0x1b,0x4a,0x80,0xbf,0x9e,0xa4,0x27,0x4a,0x5a,0x50,0xc2,0xfa,0x87,0xae,
  0xa1,0x30,0x9c,0x5a,0x59,0xe8,0xc0,0x0f,0x35,0xe8,0x35,0x17,0x83,0x84,0x22,0xcf,0x7d,0x77,0x84,0x66,
  0xd8,0x83,0xa3,0x11,0x1d,0x1f,0x2a,0xf0,0x56,0xcc,0x9e,0xbe,0x72,0xc1,0xe5,0xa7,0x1a,0x7a,0x56,0x1c,
  0xd7,0x5e,0xbc,0x24,0xee,0xe1,0x74,0x34,0x3d,0xd5,0x79,0x65,0x24,0x77,0xe2,0x41,0x45,0xbc,0x4d,0x91,
  0xc8,0xa9,0xaa,0x39,0x49,0xd3,0xc7,0xb1,0xd5,0x06,0x2c,0xae,0x1a,0x2e,0xc0,0xc6,0x2b,0x48,0x52,0x3e,
  0x65,0xc3,0x46,0xd3,0xd2,0x1a,0x4d,0x85,0x3c,0xa2,0xeb,0x11,0x53,0x46,0x92,0xb4,0x7a,0xea,0x60,0xf0,
  0xed,0x70,0xf4,0x99,0xd0,0x3e,0x6d,0xaf,0x98,0x03,0x84,0x2d,0xe8,0x5a,0x85,0x7a,0xad,0x51,0x18,0x42,
  0xff,0x01,0x2a,0x00,0xbf,0x04,0x9e,0xfe,0x13,0x54,0xad,0xc1,0x7b,0xf9,0x4d,0x97,0xfe,0xd5,0x7b,0x5c,
  0x91,0xb8,0x43,0x83,0xb3,0x64,0x4e,0xc1,0x6f,0x37,0xf5,0xd3,0x77,0x3b,0x17,0x12,0x43,0x7f,0x96,0xc4,
  0x31,0xcd,0xa4,0xae,0x3a,0x3c,0x6b,0x38,0x80,0x10,0x34,0xaa,0x39,0xad,0xaa,0x20,0xff,0xb4,0x62,0x6c,
  0xf0,0x90,0xae,0x24,0xae,0xf2,0x34,0x6e,0x61,0xd4,0x11,0xe2,0x18,0xe6,0x46,0x21,0x05,0x51,0xa0,0x2e,
  0x6d,0xe3,0xd3,0xe3,0xf8,0x50,0x79,0x5f,0x11,0x99,0x4e,0xe3,0xe7,0x7a,0xf7,0xbb,0x64,0x9a,0x98,0x03,
  0x8e,0x0e,0xe9,0x91,0x8a,0xec,0xa3,0x11,0x3d,0x9b,0x4e,0x37,0x5e,0x4a,0xaf,0x69,0xd6,0xb0,0x59,0x4f,
  0x34,0x50,0x4d,0xe3,0x5d,0xd3,0xf3,0x6c,0x8b,0xf4,0x64,0x39,0x4b,0x22,0x2d,0x78,0x80,0x8d,0x04,0xe5,
  0x23,0x77,0x0e,0x83,0xd7,0xc3,0xc6,0xee,0x8a,0xf8,0x56,0x5f,0xca,0xe1,0x78,0x1c,0x8f,0x87,0x41,0xa7,
  0xbc,0x3e,0xa3,0xa7,0xf1,0xd1,0x59,0x6c,0x6c,0x2f,0xd8,0xce,0x67,0xa8,0xf7,0x3f,0x42,0xbe,0xa8,0x33,
  0x0b,0x22,0x3a,0x5c,0xd2,0xa5,0x94,0x99,0x67,0xd3,0x69,0x3c,0x8e,0xc7,0x5b,0xd8,0x3c,0xa8,0xcd,0xef,
  0x34,0xcf,0x99,0x11,0xdc,0x6f,0x0b,0x09,0x5a,0x32,0x26,0x29,0x31,0xb4,0x50,0x0f,0x14,0x34,0x43,0xc5,
  0xdc,0x0e,0xef,0x37,0x5f,0x39,0xbf,0x7c,0x53,0x3b,0x05,0x56,0x76,0x37,0x99,0x43,0x06,0x98,0x64,0x6c,
  0xf3,0x2f,0x73,0x1a,0x27,0xa4,0x5f,0x87,0x83,0x67,0x10,0x0d,0x3a,0xeb,0xda,0x94,0x3c,0xa8,0x8c,0x6a,
  0x93,0x63,0xc9,0x5f,0xfe,0x34,0x29,0x2b,0x36,0x88,0x66,0x49,0x1a,0xf3,0xc1,0x7c,0x0c,0xb0,0x43,0x66,
  0x8d,0x85,0xbe,0xdb,0x0a,0x75,0xd3,0x46,0xe9,0x64,0x8c,0x28,0x89,0x1c,0x91,0xe2,0x82,0xb1,0xb4,0x3e,
  0xba,0x94,0x01,0x23,0x0e,0x44,0x34,0x39,0x6a,0x98,0x5e,0x2d,0xa3,0xe2,0xb6,0xf2,0x23,0x23,0x0c,0x9c,
  0x44,0xa8,0xbd,0x15,0xbb,0x40,0x9f,0xbd,0xf6,0x8c,0x1a,0xc1,0xad,0xf2,0xb9,0x1a,0x4d,0x3c,0x1f,0xd2,
  0xd8,0x6f,0xd9,0x05,0x42,0x90,0xe7,0x86,0x11,0x57,0xe1,0x5c,0xcb,0xf0,0x8e,0x1a,0xf6,0x4e,0x03,0x79,
  0x56,0x3b,0x6a,0x2d,0xf7,0x03,0x1c,0xce,0xcd,0xce,0xf9,0x81,0x48,0x57,0x9f,0x1f,0x88,0x43,0x03,0xc8,
  0xf6,0x8a,0x23,0x04,0x5a,0x4e,0x76,0xce,0xe3,0xe4,0x76,0x72,0x3e,0x1b,0x59,0xa0,0xc4,0x79,0x30,0x1b,
  0xf6,0x8c,0x5c,0x79,0x6f,0x72,0x0e,0xbb,0x09,0x09,0xf4,0xf3,0x03,0xfc,0x85,0xcf,0x56,0x94,0x92,0xaa,
  0x0a,0x7b,0x90,0xd1,0xea,0x4d,0xa0,0x7b,0xd7,0x5b,0xbe,0x03,0xbd,0x09,0x80,0xea,0x7a,0xcf,0x96,0xbd,
  0xc9,0xe5,0x6f,0xf2,0xcd,0xc1,0x6c,0x34,0x39,0x2f,0x26,0x66,0x66,0x1e,0x72,0xf5,0xbf,0x26,0x83,0x37,
  0x89,0x25,0x22,0xfa,0xf3,0x83,0x62,0x72,0x7e,0x00,0x78,0x23,0xf6,0x0a,0x11,0x20,0xb8,0x85,0x39,0x96,
  0x9e,0x95,0xc4,0x61,0x4f,0x24,0x67,0x92,0x3c,0xeb,0x99,0x93,0xc6,0x39,0xeb,0xf1,0xf5,0x72,0x81,0x09,
  0x7b,0xac,0x5c,0xd0,0xde,0xc4,0x40,0xd0,0x84,0x00,0x22,0xdf,0x9b,0xbc,0x14,0xcf,0xd9,0xb5,0xc2,0x98,
  0xa3,0x71,0xa0,0x93,0x53,0x4e,0xc3,0xf9,0x0b,0x8e,0x0c,0x90,0x65,0x0c,0x0a,0x5f,0x6a,0xeb,0x93,0x89,
  0x0a,0x3c,0xd9,0x19,0x4f,0xc4,0xab,0xaa,0x4a,0xf2,0xec,0xfc,0x60,0x36,0x36,0x81,0xd6,0x9d,0x8d,0xb5,
  0xf3,0x0c,0x47,0x6f,0x72,0xce,0x7f,0x21,0xf6,0x28,0x19,0x3d,0xd9,0x45,0xe4,0x87,0x7b,0x96,0xcc,0x56,
  0x4f,0x5e,0x67,0xf0,0xaf,0x24,0xb5,0x98,0x8f,0x8f,0x6f,0xc0,0xc9,0x0b,0x05,0x06,0x1f,0x26,0x9f,0x59,
  0x5e,0x6c,0x19,0x88,0x14,0x91,0x74,0x81,0x03,0x19,0x0e,0x83,0x32,0x20,0x5b,0xd5,0xb3,0xb2,0xfc,0x96,
  0xa4,0x49,0x4c,0x18,0x35,0x17,0xa6,0x02,0xce,0x9e,0x1a,0x3d,0x1b,0x03,0x2b,0xc8,0xa1,0x6d,0x5a,0x60,
  0x36,0xa6,0x37,0x39,0x47,0x9a,0xc2,0xe1,0x4f,0xd8,0x9b,0x96,0xf4,0x6f,0x0b,0x9a,0x45,0xab,0x77,0x3f,
  0xff,0xde,0x9b,0x7c,0x82,0x87,0x0a,0xd2,0x73,0xaa,0xfd,0xfc,0x00,0x7b,0x1b,0xd4,0xab,0x33,0x28,0xbd,
  0xc9,0x39,0x3e,0x20,0xce,0x06,0x2c,0x71,0xa0,0x66,0xb6,0x61,0xf4,0x2c,0x79,0xdc,0xba,0x25,0xe9,0x82,
  0x86,0xbd,0xf1,0xd1,0x68,0xdc,0x83,0xbc,0x9c,0xfa,0x49,0x96,0xf0,0xf3,0x64,0xdc,0xb3,0x2a,0x46,0x8b,
  0xb0,0x37,0xea,0x59,0x00,0x26,0x29,0x69,0xcc,0xc3,0xf0,0x79,0x1e,0x53,0x38,0x40,0x8b,0x92,0x39,0x49,
  0xb5,0x1d,0x32,0xb8,0x96,0xe3,0xf7,0xee,0xe7,0xdf,0x0d,0xde,0xeb,0x10,0x04,0x49,0x16,0xad,0xa9,0x4e,
  0x4c,0x98,0xe4,0x22,0xd5,0x4d,0x6f,0xf2,0xe2,0xf3,0xbf,0x2a,0xaa,0xf0,0xb4,0x05,0x2e,0x9f,0x54,0x37,
  0xff,0x06,0x2b,0xea,0x69,0x5d,0x4f,0x0e,0xcf,0x0f,0x78,0x17,0x39,0xbd,0x36,0x49,0x9d,0x5c,0x30,0xc8,
  0x08,0x03,0x05,0xf5,0xf0,0x27,0x27,0x1a,0x62,0x24,0xc8,0x34,0x14,0x34,0x3a,0x39,0xd4,0x28,0x24,0xa8,
  0x09,0x6d,0x35,0x3d,0x0c,0xa8,0xef,0x05,0xdd,0x75,0xb9,0x7a,0xf1,0xf9,0x5f,0xad,0x28,0x8f,0x69,0x73,
  0x6f,0xbe,0x73,0x9e,0xff,0x09,0xd2,0x16,0x77,0x65,0x6f,0xf2,0xe2,0xe3,0xaf,0x9f,0x3a,0x89,0x5b,0xdc,
  0x95,0x06,0x75,0xb1,0xf7,0x3f,0x45,0x5e,0x18,0x29,0xe9,0x8b,0xbf,0xb7,0x13,0x78,0x34,0x3e,0xfd,0x0e,
  0x0a,0x17,0x77,0x65,0x27,0x89,0x3f,0xfe,0xfa,0xe9,0x71,0x1a,0x3f,0x61,0x2a,0x83,0xc8,0x85,0x5c,0x26,
  0x64,0x4e,0x91,0x27,0x2d,0x92,0xc5,0x16,0x4e,0x46,0x4a,0x6a,0xcd,0x48,0x19,0xdf,0xc1,0x0f,0xa1,0x00,
  0x11,0x83,0xca,0xb5,0xb2,0x9c,0x59,0xf1,0x4f,0x73,0x0f,0x8c,0x42,0x1b,0x0a,0x8c,0x1e,0xfe,0xf1,0xf7,
  0xff,0x3c,0x39,0xb4,0xaa,0x19,0x8c,0x66,0x33,0x6a,0x55,0x64,0x4e,0x2d,0x92,0x91,0x34,0xbf,0xc6,0x23,
  0x64,0xf0,0x85,0x03,0x0b,0x66,0x4c,0x2a,0x09,0x3e,0xa5,0xb1,0x25,0x34,0x12,0x4d,0x57,0x02,0xfa,0x43,
  0xda,0x0a,0x94,0xd5,0x6b,0xa1,0x0c,0x2d,0x96,0xcc,0xd1,0x46,0x6c,0x53,0x58,0x4f,0x60,0x9f,0x78,0xc1,
  0x56,0x1f,0x69,0x09,0x11,0x43,0x0f,0xb4,0x20,0x3c,0x5b,0xf1,0xa2,0x04,0x27,0xe0,0xf2,0x37,0x0b,0x8f,
  0x2a,0xaa,0x2e,0xce,0x82,0x8e,0x3a,0x67,0x19,0x80,0x46,0xc3,0x1f,0xbf,0x9f,0xc3,0x74,0x08,0x82,0xd1,
  0x8c,0xa6,0xed,0xfc,0x76,0x36,0x6c,0xf3,0xc0,0x68,0xd8,0xcd,0x6e,0x00,0xb2,0x8b,0xdd,0x2e,0x7f,0xe3,
  0x6b,0x8f,0x56,0x51,0x4a,0xad,0xc2,0x9c,0xb4,0x93,0xf5,0x1e,0x9f,0xf5,0x31,0xf1,0xd6,0xf6,0xa1,0xa0,
  0x65,0x92,0xc7,0xef,0x2a,0xdc,0x84,0x62,0x91,0x56,0x88,0x43,0x92,0xc7,0xdf,0x61,0x48,0x14,0x0c,0x41,
  0xbd,0xfa,0xb9,0x63,0x15,0xd2,0x60,0x8c,0x86,0x5b,0x96,0xa1,0x4c,0xc7,0x43,0x66,0x62,0x5e,0x75,0x58,
  0x89,0x47,0x96,0x9a,0x51,0x76,0x97,0x97,0x37,0x6f,0x21,0x46,0xbd,0x25,0x29,0xac,0xf9,0x23,0xb9,0x46,
  0x89,0x9b,0x26,0xe5,0x9c,0x60,0x59,0x45,0x22,0xde,0xaa,0xe5,0xf3,0x83,0x01,0x5c,0x67,0x1b,0x80,0x58,
  0x70,0xc7,0x8b,0x1a,0xf9,0xbc,0x40,0xc0,0xd2,0x7a,0x0e,0x87,0xc3,0xde,0xe4,0xf5,0x2d,0x2d,0x57,0xd6,
  0xd8,0xaa,0x68,0x94,0x67,0x71,0x75,0x7e,0xc0,0x3b,0x35,0x3b,0x1f,0x6a,0x9d,0x0f,0xdb,0x9d,0x0f,0x38,
  0x6e,0xdb,0x74,0xcc,0xa7,0x37,0xd6,0x87,0xf7,0x07,0x1f,0xde,0xbc,0x11,0xf2,0x6a,0x95,0x8b,0xac,0xb2,
  0xee,0x12,0x36,0x4b,0x32,0x8b,0x92,0x68,0xa6,0x04,0xcd,0xb3,0x2e,0x67,0xd4,0x8a,0x48,0x59,0x26,0xb4,
  0x04,0x2d,0x51,0x90,0x45,0x05,0x5e,0x45,0x5e,0xd6,0xae,0xa9,0xa2,0x91,0xd0,0x16,0x9a,0x07,0x85,0xf9,
  0x70,0xb9,0xdb,0xd5,0xe2,0x6a,0x9e,0x30,0x8d,0x02,0x2f,0xe0,0xad,0xe6,0xe6,0x08,0x4f,0x6a,0xe7,0xfc,
  0x00,0xdc,0x27,0x1d,0x6f,0x91,0xb3,0xe6,0xee,0xad,0x7a,0x28,0xf3,0x94,0xa2,0xb7,0xc7,0x16,0x95,0x94,
  0x9d,0xe4,0x16,0xf8,0x2c,0x4f,0x13,0x46,0x7b,0x93,0x5f,0x49,0x02,0xa0,0x11,0x5d,0x50,0x80,0x9a,0x73,
  0x2d,0x70,0x3d,0x40,0x0f,0x15,0xea,0x7e,0x48,0x02,0x33,0x57,0xdc,0xeb,0x55,0x4e,0x27,0x29,0xe3,0xde,
  0x56,0xff,0x55,0xcc,0x6c,0xb0,0x97,0x4a,0x42,0xf7,0x26,0x9a,0x4f,0xab,0x75,0x47,0xe5,0x58,0x7b,0xda,
  0x8b,0x02,0x3c,0xc2,0x17,0xb0,0x1c,0x63,0x8f,0xde,0xe7,0xd6,0x94,0xd2,0x18,0x02,0x7b,0x6b,0x45,0x99,
  0xc9,0xd4,0xba,0x3e,0x86,0x20,0xa8,0xd7,0x6e,0x1a,0xf0,0x1a,0x1e,0xe1,0x0e,0x33,0xfa,0x16,0x1f,0x3b,
  0x7c,0xff,0x3f,0xfe,0xf1,0x1f,0x35,0xd4,0x0e,0x38,0x18,0x5f,0x69,0x80,0x2e,0xf1,0xd9,0x88,0x08,0xba,
  0x07,0x42,0x76,0x57,0x1b,0xf7,0x3e,0x6f,0xee,0x08,0xec,0x55,0xbd,0xc8,0x69,0x99,0xcf,0x71,0x93,0x5e,
  0x7f,0xfe,0xe8,0x19,0xc2,0x2b,0xd5,0x55,0xaa,0x4c,0x87,0x88,0x1d,0x1b,0x06,0x85,0xb7,0x42,0x23,0x43,
  0xd6,0x4a,0x74,0xf7,0x17,0x82,0xa9,0x2c,0x9f,0x27,0x19,0x48,0x70,0xcc,0x26,0xe7,0x71,0xac,0xed,0x02,
  0xe1,0xdd,0xdf,0xc8,0xde,0xbd,0xc9,0x1f,0x7f,0xff,0x2f,0x41,0x73,0xeb,0x1c,0x13,0xa0,0xc2,0x01,0xc5,
  0x9f,0xe7,0x07,0x71,0xdc,0xb1,0x17,0x9d,0x18,0xa0,0x93,0xc9,0x27,0xd4,0xa7,0x7a,0x01,0x5e,0x25,0x4e,
  0xf2,0x1d,0xa0,0xd0,0xa7,0xea,0x80,0x85,0x3e,0x54,0x03,0xd8,0x41,0x0c,0x15,0x74,0x07,0x82,0xa1,0xb7,
  0xb1,0x36,0xba,0xfb,0x2a,0xf7,0xd3,0xb3,0x38,0x6f,0xb4,0x58,0x17,0xbb,0x70,0xce,0x2d,0xea,0x31,0x18,
  0x1b,0x0a,0x29,0x24,0x29,0x2d,0x41,0xf9,0x63,0x88,0xfa,0xf0,0xa4,0x0f,0xc9,0x8b,0xb2,0x35,0x9a,0x27,
  0x51,0x6f,0x53,0x9c,0x94,0x6c,0x55,0x07,0x76,0x3c,0x21,0xa4,0x90,0xfe,0x92,0x09,0x7a,0x40,0x69,0x60,
  0x76,0x4d,0xab,0xad,0x42,0x23,0x13,0x81,0xa6,0x68,0x4b,0x67,0x43,0x28,0x42,0xa2,0xb4,0x60,0xaf,0x15,
  0xba,0x23,0x36,0x6c,0xf9,0x22,0x4d,0xf3,0x08,0x55,0x5f,0x8f,0x57,0xf5,0x89,0x2a,0x43,0x7f,0x34,0xfc,
  0x51,0xa8,0xd9,0xae,0xd8,0x1f,0xb2,0x8f,0x1c,0x04,0xfc,0xda,0x0a,0xe4,0x4c,0x02,0x79,0xf3,0x66,0xeb,
  0x4a,0x78,0x86,0xb2,0xa7,0xd1,0xa8,0x94,0xa1,0xdf,0xab,0x05,0x5b,0xe9,0x91,0xe0,0xa7,0x37,0xbe,0x85,
  0x6e,0x50,0x23,0xd6,0x57,0x03,0x7e,0x05,0xb4,0x60,0xc2,0x7c,0x3a,0xf5,0xad,0xb3,0xba,0xab,0x98,0x55,
  0xc9,0x9f,0x48,0x50,0x9b,0xcc,0x29,0xa9,0xc7,0x48,0x79,0x0d,0xfa,0xaa,0xcd,0xa6,0x1c,0x21,0xc5,0xa6,
  0x31,0x9b,0x5c,0x26,0x73,0x30,0xe7,0x1a,0xd1,0x35,0x0f,0x4f,0x03,0x50,0xcc,0x48,0x45,0xdb,0xc3,0xff,
  0x92,0xe6,0x57,0x24,0xe5,0xe3,0x93,0x2c,0x4a,0x17,0x98,0x29,0xe2,0x76,0x09,0x0d,0x95,0x09,0xe5,0x1a,
  0xbb,0xb7,0xc1,0x68,0x2b,0x30,0xfd,0x9c,0xf6,0x12,0x3e,0xe2,0x1b,0x43,0xd6,0xd2,0x49,0xd3,0xbc,0x82,
  0xc9,0xe4,0x73,0x29,0xa2,0x70,0xec,0x68,0x65,0xba,0x14,0x1c,0x47,0x74,0xf7,0x21,0x2d,0x9f,0x5b,0xd5,
  0x5d,0xc2,0xa2,0x59,0x92,0x5d,0x7b,0xd6,0x9b,0xa4,0x9c,0xa3,0xdb,0x2f,0x4c,0x74,0x52,0xa1,0xc7,0x0f,
  0x7b,0x96,0xc5,0x14,0x58,0x9f,0x66,0x0c,0xe0,0xd3,0xec,0x96,0xa6,0x79,0x41,0xad,0x39,0x25,0xd5,0xa2,
  0xa4,0x73,0x9a,0x31,0xef,0xcf,0x8a,0x61,0xcb,0xfd,0x69,0x08,0xa2,0x08,0x16,0x7e,0x49,0xb2,0x9b,0x86,
  0xdd,0xfa,0x95,0x5e,0x7d,0xce,0xa3,0x1b,0xca,0x64,0x2d,0x6b,0x33,0x67,0xb4,0x8d,0x8f,0x5e,0x8a,0xf0,
  0x86,0xdb,0x6a,0x74,0x35,0xae,0xa9,0xb1,0x07,0x3a,0x3e,0x9f,0xb9,0xd9,0x7b,0x95,0x54,0xa4,0x9c,0xd3,
  0xb8,0xb5,0x97,0xd1,0x8c,0x46,0x37,0x9a,0xcf,0xd6,0xde,0x4a,0xe9,0x93,0x99,0xbc,0xf0,0x8e,0x2c,0x93,
  0xf9,0x62,0x6e,0xee,0xd3,0x1d,0x49,0xd8,0x56,0x4c,0x80,0x87,0x31,0xdb,0xa5,0x83,0xf9,0x85,0x54,0xcc,
  0x84,0x51,0xd1,0xcc,0x84,0x91,0x92,0x8a,0xbd,0xd4,0x7a,0x98,0x00,0xf4,0x37,0x3c,0x02,0xd8,0x8a,0xc0,
  0x4b,0x78,0xfb,0x08,0x4b,0x7e,0xc8,0xd2,0x15,0xf0,0x0e,0x5d,0x16,0x69,0x12,0x25,0xcc,0x12,0x29,0x30,
  0x08,0xd9,0x24,0xad,0x2d,0x52,0xce,0x4d,0x06,0xad,0x3c,0xeb,0x85,0x85,0xa1,0x5d,0x76,0x6d,0xe5,0x25,
  0x4f,0x31,0x36,0x96,0xc5,0xf2,0xa2,0xb2,0x2e,0x7f,0xf3,0xac,0x4f,0xb4,0xde,0x70,0x2b,0xa3,0xb7,0xb4,
  0xb4,0x4a,0x5a,0x2d,0xe6,0xc0,0xe0,0x56,0x45,0x79,0x7c,0x08,0x87,0x73,0x30,0x32,0x22,0xa9,0x08,0x2e,
  0x75,0x2e,0xd5,0xf8,0x11,0xd2,0xe7,0xa0,0xd5,0x3a,0xf9,0x56,0x8f,0x38,0xa5,0xff,0xc0,0x19,0x74,0x2b,
  0x6f,0xcd,0x8b,0x94,0x82,0x12,0xec,0xd6,0x2f,0x57,0x8b,0xb2,0x82,0xd8,0xcf,0xd8,0x81,0x45,0xc5,0xf2,
  0x39,0x0c,0x00,0x6b,0x61,0x74,0x67,0x4b,0xd8,0x74,0xb3,0xfb,0xfb,0x3c,0x1b,0x74,0xf5,0x05,0x0d,0xdf,
  0xee,0xfd,0x09,0xc5,0xbd,0xa4,0x15,0xcb,0x4b,0x6a,0x4d,0x49,0x92,0x2e,0xca,0x86,0xb6,0x12,0x2f,0xdf,
  0x88,0x77,0x8f,0x6c,0x70,0x8b,0x1e,0x56,0x9c,0x53,0xae,0x32,0xc4,0x7e,0x59,0x25,0x8d,0x28,0x0f,0x22,
  0x08,0x43,0x47,0xab,0xa4,0xf3,0x9c,0x49,0x7f,0x4b,0xdf,0x89,0xed,0x64,0x7f,0x85,0xd5,0xf3,0x0f,0xd2,
  0x1a,0x25,0xd3,0x58,0x09,0x2f,0xb9,0x17,0x12,0xab,0x53,0xe1,0x4b,0xd1,0x22,0xd7,0x02,0x9b,0xcc,0x6e,
  0x5c,0xa1,0x93,0x38,0x2e,0x69,0x55,0xb5,0x88,0xfb,0xf6,0x63,0x43,0x82,0x5f,0xbc,0xec,0xec,0x3b,0x27,
  0x51,0xb7,0xda,0x2f,0x29,0x54,0x20,0x83,0x8a,0x33,0xa8,0xcf,0x1b,0xcd,0x21,0x52,0x29,0x1b,0x5d,0xa7,
  0xa2,0xb1,0xd1,0x55,0xee,0x43,0x53,0x8b,0xc9,0x0d,0x02,0x97,0xbf,0xb1,0xa7,0x1a,0xff,0xf3,0xc3,0x40,
  0xee,0x24,0xe4,0xd3,0x29,0x38,0x2b,0xef,0x45,0x93,0xf0,0x76,0xd4,0x04,0x49,0x65,0x2d,0x32,0x72,0x4b,
  0x92,0x14,0x44,0x5a,0x44,0x6c,0x8b,0xb2,0x04,0xfb,0xc0,0x1a,0xe1,0x07,0xe5,0xbd,0x6f,0xb2,0xfc,0x2e,
  0xf3,0x2c,0x5d,0xc9,0x54,0x98,0x6c,0x8a,0x85,0x3e,0xf5,0xac,0x2f,0x15,0xb5,0x78,0xb2,0x3b,0xb7,0x84,
  0x87,0x80,0x0a,0x24,0x8b,0xa1,0x45,0xcf,0x80,0x2b,0x67,0x5d,0xb1,0x4f,0x47,0x7e,0x01,0x0f,0x01,0x7b,
  0xed,0xbb,0x08,0x20,0x1a,0xe5,0x00,0x8e,0x50,0x95,0x07,0xa1,0x8e,0x16,0x30,0x24,0x93,0x4f,0xfc,0x42,
  0xc5,0x64,0xc7,0x5e,0x54,0x70,0xd6,0x51,0x26,0x11,0xb3,0x83,0x9d,0x7e,0xdf,0x09,0x27,0xeb,0x9d,0x28,
  0xcf,0x2a,0x66,0xfd,0x10,0x26,0x71,0x38,0x89,0xf3,0x68,0x81,0x36,0xf0,0x9a,0xb2,0xd7,0x29,0x9a,0xc3,
  0x9f,0x56,0x6f,0xe3,0x7e,0x12,0x3b,0x2e,0xc6,0xfe,0x55,0xf8,0xd5,0xd6,0xb3,0xd9,0xb6,0x6b,0x93,0xea,
  0x06,0xfe,0x2e,0xee,0x4a,0xdb,0xb5,0xb5,0x14,0x8f,0xed,0xda,0x32,0x65,0x61,0xbb,0x76,0x2b,0x98,0xb7,
  0xbf,0x05,0x62,0x6a,0x51,0xf8,0xfe,0x4b,0x32,0x4f,0x58,0x15,0xae,0x6b,0xf0,0x49,0xf6,0xee,0xe7,0xdf,
  0x7d,0x48,0x87,0xbb,0x75,0x23,0x59,0xf2,0xc6,0x13,0xad,0xf1,0x33,0xa3,0x05,0xb4,0x8e,0x5c,0x52,0xdd,
  0xbc,0x83,0xa3,0x53,0xfc,0x41,0x96,0xfe,0xc9,0xa1,0x0b,0x98,0x89,0x36,0xf8,0x45,0x96,0xfe,0x68,0x7c,
  0xea,0x02,0xa2,0xef,0x92,0x4c,0xe0,0xea,0x0f,0x79,0x03,0x59,0xca,0x86,0xb3,0xa1,0x2b,0xb0,0x4f,0xb2,
  0x77,0x95,0x3f,0x96,0x4f,0x64,0xf9,0xae,0x82,0xea,0xb4,0x8d,0xc4,0xbe,0x24,0x59,0x9c,0xcf,0xc3,0x8c,
  0xde,0x59,0x5f,0x92,0x8c,0x3d,0x7f,0x51,0x96,0x64,0xd5,0x1f,0x9d,0x38,0x41,0x54,0xae,0x0a,0x96,0x03,
  0x29,0x3f,0x61,0x1f,0xcc,0xaf,0x55,0x7d,0x3e,0x00,0x6e,0x16,0xc0,0xf0,0x28,0x4d,0x68,0xc6,0xde,0xc6,
  0x21,0x8e,0xf3,0x20,0x90,0x13,0x3d,0xdc,0x2c,0x9c,0x64,0x1e,0xcb,0x3f,0x33,0x48,0xdf,0x01,0x44,0xaf,
  0x20,0xf1,0x67,0x38,0x9e,0xe9,0x8f,0x5d,0x7b,0x68,0x3b,0x8e,0xf7,0xd7,0x3c,0xc9,0xfa,0xb6,0xed,0x04,
  0x3b,0x29,0x65,0x56,0x2a,0x28,0xe8,0x79,0x9e,0x41,0xd3,0x8d,0x0b,0xf6,0xf2,0x33,0x46,0xd0,0x61,0xb6,
  0x48,0x53,0x7c,0xfe,0x82,0xc1,0x73,0x38,0x74,0x31,0x30,0x08,0xa7,0x24,0xad,0xa8,0x2b,0x0f,0x8a,0x3e,
  0x51,0x12,0xcb,0xb6,0xbc,0xa0,0x25,0xb2,0x39,0x1f,0x0b,0x3a,0xa6,0x0c,0x87,0x6e,0x91,0xa7,0xe9,0x4b,
  0x99,0xf7,0x2c,0xf9,0xbb,0x28,0x9f,0xcf,0x49,0x16,0x37,0x9b,0x85,0x0c,0xbc,0x2e,0xf2,0x68,0x16,0x0e,
  0x39,0xb2,0x15,0x3a,0x3a,0xfc,0x3d,0xff,0xfd,0xa5,0x4c,0x43,0xdb,0x16,0x0f,0x9f,0x28,0x2b,0x57,0xe1,
  0x50,0x3c,0x89,0x91,0x6e,0x59,0x44,0x9f,0xf9,0x9e,0x03,0xe2,0x02,0x59,0x94,0xc4,0xeb,0x70,0xbd,0x71,
  0x13,0x7e,0xa9,0x88,0xa3,0x2d,0xcc,0xe6,0xdb,0x98,0xcf,0x21,0x02,0x9e,0x97,0x33,0x92,0xa6,0x34,0xbb,
  0xa6,0x35,0x21,0xba,0x9a,0x38,0xe4,0x17,0x2c,0x1c,0xba,0x9a,0xaf,0xd1,0x7c,0x46,0xef,0x01,0x47,0x49,
  0x6e,0x10,0xb3,0x7c,0x2a,0x22,0xe4,0x88,0x77,0xa4,0xe8,0x3b,0xf2,0xdd,0x14,0x6e,0x4c,0xd1,0x30,0x0b,
  0x27,0x90,0xd2,0xc9,0xa7,0x56,0x16,0x86,0xa1,0xcd,0xd3,0x78,0xf6,0xde,0x1e,0x4f,0x63,0x7a,0x49,0xf5,
  0x06,0xfb,0xf5,0x33,0xc7,0x5d,0x24,0x19,0x83,0xfe,0xea,0x15,0x88,0xcf,0x35,0x2d,0xfb,0x99,0xb3,0xb7,
  0x97,0x4d,0xc2,0xe1,0xde,0x5e,0x76,0x1e,0x0e,0x97,0x53,0xf1,0x47,0xce,0xc4,0x61,0x86,0xfd,0xcc,0x8d,
  0xc3,0xa1,0x13,0x4e,0xa6,0x12,0xe2,0x05,0x30,0xd4,0x2f,0x39,0xdc,0xd8,0x12,0x6c,0x65,0xd3,0x6c,0xf0,
  0xe5,0xb3,0xed,0xae,0xe7,0xdc,0x79,0x7b,0x53,0xf2,0x9b,0x50,0xaf,0x92,0xeb,0x84,0x55,0x7e,0xbc,0x71,
  0x7c,0xfb,0x8f,0xbf,0xff,0x97,0x2d,0x41,0x43,0xa1,0x41,0xd8,0x4f,0x62,0x17,0x93,0x69,0xa0,0x40,0x7e,
  0x00,0xed,0xe0,0x41,0xbb,0xb8,0xed,0x15,0xe2,0xab,0x60,0xe3,0xce,0x48,0xf5,0x06,0xb8,0x30,0xac,0xc2,
  0xc9,0xee,0x6e,0x75,0xc1,0x0b,0xe4,0xf6,0xf6,0x2a,0xfe,0x63,0x17,0x56,0x8f,0x57,0xb0,0x04,0x6c,0xbe,
  0xd7,0x1f,0x0a,0x9a,0x85,0xa0,0x9a,0xf8,0xe3,0x05,0x9e,0x62,0xaf,0xd0,0x02,0x86,0x61,0xa8,0x5c,0x64,
  0xef,0xc3,0xc7,0xd7,0xef,0xe5,0xc8,0x44,0xa9,0x15,0x1c,0x29,0xd6,0x5b,0x73,0xfd,0x85,0x87,0x86,0xfc,
  0xfa,0xc2,0x6b,0xe9,0x21,0xe7,0xa2,0xee,0x26,0x7a,0xb5,0x3b,0xf9,0x90,0x60,0x94,0x93,0x09,0x9f,0xc0,
  0x9c,0xcb,0xe0,0x45,0xaf,0xc3,0xc7,0x85,0x99,0x9e,0xd0,0xc9,0x3f,0xae,0x27,0x42,0x97,0x51,0x4c,0xf3,
  0x8e,0xb0,0x99,0x07,0x45,0x78,0xc7,0xc3,0xe1,0xd0,0xad,0xd7,0xdb,0x77,0xf6,0x15,0x3e,0x7d,0x67,0x1f,
  0xf0,0x74,0x82,0x9d,0xe9,0x22,0x8b,0x84,0xe7,0xcc,0xde,0xf1,0x8c,0x5f,0x1f,0x77,0xc5,0xbd,0x49,0xb2,
  0x38,0xb4,0x6d,0x67,0x0d,0x1b,0xd6,0xb7,0x45,0x3a,0xd0,0x16,0xdb,0x19,0xfc,0x50,0x37,0x39,0x1e,0xda,
  0x9f,0xf7,0x90,0x8b,0x55,0x8d,0xfb,0x7d,0x00,0x70,0x61,0x5b,0xf6,0x3e,0xfc,0xf0,0x41,0xf7,0x6c,0xb4,
  0xe9,0x66,0xf9,0x9d,0x90,0x9d,0xbe,0x9c,0xa2,0x15,0x79,0xd8,0x42,0x4e,0xf7,0xf6,0x94,0x88,0xee,0x86,
  0x28,0x45,0x7b,0x7b,0xfa,0x96,0x51,0x74,0xb3,0xe3,0x0b,0xfb,0x05,0x58,0x55,0x33,0xb6,0xb1,0x7d,0x5b,
  0x86,0x2f,0x36,0xaf,0x7e,0xe9,0xdb,0xcd,0xa0,0xc0,0x36,0x45,0xf7,0x82,0x4b,0x45,0xbf,0xff,0x8a,0x30,
  0xea,0x65,0xf9,0x5d,0xdf,0x19,0x18,0x1d,0x9c,0x83,0x11,0xd0,0x76,0xe4,0xec,0xdb,0x56,0x65,0x91,0xeb,
  0xdc,0xe6,0xac,0x2f,0xe1,0xb7,0xe2,0x06,0xbb,0xad,0x0b,0xf8,0x3a,0x2e,0x70,0x9c,0x2f,0x26,0x6c,0x76,
  0x72,0x0c,0x92,0x71,0xaf,0xa1,0xef,0xac,0x75,0xe5,0x15,0x98,0xca,0x2b,0xe8,0x54,0x5e,0x41,0x5b,0x79,
  0x05,0xc6,0x06,0x34,0xa6,0x81,0xe2,0x9e,0x3a,0x5f,0xd2,0x77,0xd6,0x9c,0xcb,0x78,0x56,0x9c,0xab,0x98,
  0xfe,0x0f,0x7d,0xc3,0x84,0x3b,0x1e,0xe7,0x0b,0x17,0x6e,0x5a,0x86,0x8a,0x07,0x87,0x2e,0xff,0x99,0x64,
  0xfd,0xd1,0x70,0xe8,0x36,0x35,0x17,0x1f,0x73,0x81,0xff,0xf8,0x43,0x07,0xb9,0x4a,0xcf,0xf7,0xd8,0x8e,
  0x87,0xb9,0x1a,0x8f,0xdf,0x2a,0x05,0xd8,0xfb,0xf6,0x8f,0x36,0x74,0x33,0x73,0x3a,0x8d,0x8e,0x30,0xd9,
  0x00,0x7a,0x3b,0xd8,0x9d,0xef,0x8a,0x91,0xb2,0xb1,0x5d,0xdb,0xcc,0xd9,0xd8,0xfb,0x62,0x13,0x38,0xf7,
  0x8f,0x70,0xa4,0xd3,0x1c,0x0a,0xc9,0x1b,0x18,0x2a,0xb2,0x37,0x6a,0x10,0xcc,0xd7,0x35,0x50,0x9d,0x96,
  0xd9,0xee,0x03,0xe0,0xe5,0x51,0xb8,0xed,0xfe,0x80,0x0f,0x8a,0x9a,0xf2,0xbd,0x3c,0xcd,0xe5,0x1d,0xc0,
  0x81,0x52,0x3d,0xb4,0x9d,0x9b,0x93,0xf2,0xe6,0x15,0x98,0xe8,0xbe,0xb3,0xe6,0xa6,0x1a,0x72,0xcf,0x40,
  0x2c,0x7c,0xb2,0x1d,0x4f,0xe4,0xa4,0x39,0xe7,0x74,0x6c,0x74,0xc0,0xf3,0xe4,0x3f,0xf1,0x72,0x0f,0x93,
  0x2f,0x20,0x56,0xec,0x13,0xf7,0xca,0x59,0xff,0xd0,0x27,0x8e,0x47,0xe2,0xf8,0xf5,0x2d,0xcd,0xd8,0x2f,
  0x49,0xc5,0x68,0x46,0xcb,0xbe,0x8d,0x07,0x52,0xb6,0xdb,0xe7,0xaa,0xfe,0x4a,0x60,0x18,0x62,0x6f,0xae,
  0xe8,0x35,0x04,0x83,0x0d,0x6c,0xf6,0xd5,0x63,0x70,0x92,0x69,0xbf,0x06,0x05,0x66,0xa0,0xc3,0xfc,0x29,
  0x86,0x94,0xfd,0x1c,0xc7,0xa9,0x27,0x0d,0xeb,0xf6,0xe6,0xfc,0x9b,0x1d,0x5c,0x93,0xf4,0x4b,0xe5,0x89,
  0xbf,0xed,0x04,0xa2,0x9d,0x7b,0xaa,0xf5,0x41,0xb5,0x7a,0x63,0x3a,0xaf,0xf5,0xd1,0xa2,0x0d,0xd7,0x09,
  0xca,0xbe,0x30,0x35,0xb1,0x95,0x4f,0xad,0x96,0x17,0xfc,0xb0,0xab,0xeb,0x70,0x23,0xb9,0x95,0x2a,0x6a,
  0x09,0xba,0xee,0x6e,0xec,0x9a,0x10,0x57,0x8c,0xc0,0x69,0x1c,0xee,0x1a,0xae,0xda,0xfd,0xfd,0xee,0xae,
  0xf2,0xd3,0xda,0xd8,0x7a,0x1e,0xbf,0x84,0x54,0xe9,0x04,0x31,0x68,0x60,0xac,0x57,0xe2,0x2b,0x0f,0x9b,
  0x42,0x31,0x69,0x80,0x7c,0x5a,0xa4,0xc0,0x74,0xcd,0x77,0xf7,0xf7,0xbb,0xc8,0x8f,0xd0,0x07,0x6b,0x88,
  0x3a,0xfb,0x60,0x97,0xfb,0xfb,0xdd,0xda,0xd4,0xf7,0x1d,0xc0,0xbd,0x43,0xef,0xdf,0xdf,0x4b,0xff,0x41,
  0x33,0xe4,0xce,0xfd,0xbd,0xde,0xb5,0x12,0x5e,0x81,0x5d,0xd2,0x08,0x8a,0x29,0x93,0xec,0xda,0xe6,0x08,
  0xe4,0x85,0x3e,0x7f,0xed,0xc2,0x86,0x21,0x7f,0x69,0x58,0x2d,0x2a,0x1c,0xe5,0x3e,0xdc,0xd7,0x96,0x84,
  0xce,0xc0,0xd3,0x69,0xfb,0xd2,0x1a,0x71,0x6f,0x80,0xb6,0x1f,0xae,0xfe,0x4a,0x23,0xe6,0xdd,0xd0,0x55,
  0xd5,0x87,0x21,0x8e,0x93,0x4c,0xfb,0xc2,0x29,0x00,0x70,0x17,0xde,0xd7,0x9b,0x6f,0x8e,0x03,0xaf,0xbe,
  0xde,0x7c,0x0b,0xa1,0xe9,0xeb,0xcd,0x37,0xe1,0xfd,0x93,0x34,0xd5,0x03,0x9e,0x9f,0x7f,0xf7,0xbf,0x42,
  0x47,0xaf,0x11,0x03,0xb9,0x8d,0x46,0x8c,0x81,0x1a,0x8d,0x22,0x06,0xba,0xbf,0xb7,0x49,0xb6,0xb2,0xbf,
  0x41,0x00,0x24,0x80,0xf1,0x98,0xc8,0x55,0xbf,0xc9,0xd2,0x1d,0xe1,0x7b,0xbe,0xdb,0x0f,0xf7,0x2a,0xee,
  0x54,0x07,0x1e,0x47,0xb9,0xf5,0x43,0xdd,0xc5,0x84,0xb4,0xa5,0xa3,0x26,0x5e,0xa2,0xa7,0x19,0x84,0xb9,
  0x75,0x9b,0x8a,0xc3,0xe4,0x38,0x63,0x82,0xa7,0x0d,0x93,0x12,0x29,0x06,0x69,0xd1,0x9c,0xab,0x37,0x40,
  0x40,0xe7,0x8e,0xbe,0x69,0xfb,0xfa,0x35,0x89,0xdd,0xaf,0xf3,0x24,0x73,0xe7,0x64,0xe9,0xc2,0x59,0xfa,
  0xb7,0x6f,0xf5,0x3e,0xd3,0x8c,0x95,0x09,0xad,0xfa,0x24,0x4d,0x1d,0x67,0x2d,0x1a,0x49,0x55,0x25,0xd7,
  0x59,0x1f,0x85,0xc6,0x5d,0xeb,0x43,0x41,0x1f,0x89,0xb0,0x0c,0x26,0x6d,0x70,0xdd,0x9b,0xbc,0x9c,0xf7,
  0x23,0x67,0xdd,0x94,0x57,0x2e,0xab,0x1a,0x23,0x45,0x17,0xde,0xd7,0x24,0xfe,0xe6,0x08,0xb9,0xe4,0x2a,
  0x50,0x78,0xf0,0x11,0xbe,0x09,0xb8,0x8d,0x91,0x0a,0x4b,0x69,0x49,0xdd,0xf0,0x04,0xc2,0xcc,0x74,0x74,
  0xd2,0x8c,0x4f,0x20,0x7c,0x80,0x76,0xaf,0x0e,0xcf,0xa0,0xd3,0xdc,0x18,0x8b,0xc4,0xd3,0xf5,0xfe,0xa2,
  0x72,0xd6,0x25,0x65,0x8b,0x32,0x13,0x61,0x10,0xb4,0x48,0x8f,0x6c,0x51,0x1d,0x8c,0xe8,0x89,0x7b,0x88,
  0x8e,0x97,0x70,0xba,0x4c,0x20,0x2a,0xa4,0x14,0xbe,0x05,0x58,0x10,0x43,0x87,0x38,0x12,0x38,0xda,0x40,
  0x56,0xae,0xd6,0xfc,0xad,0x07,0x63,0xfb,0xff,0xfb,0xf3,0x87,0xf7,0x5e,0x85,0xe4,0x4a,0xa6,0x2b,0x01,
  0xc3,0x09,0xc4,0x18,0x34,0xa7,0x9b,0x88,0xb0,0x68,0xb6,0x36,0xc0,0x6c,0x36,0x3b,0x35,0x12,0xc2,0x59,
  0x50,0x8e,0x7a,0x5f,0x2d,0x48,0xb9,0x45,0x47,0x0f,0xba,0xe6,0x70,0x8b,0xd6,0xa0,0x0d,0x10,0xa2,0x9a,
  0x7d,0x2a,0x22,0x08,0xa7,0xf0,0xc2,0x99,0xab,0xeb,0x1f,0xe1,0xf3,0x85,0x75,0x48,0x09,0xa9,0x04,0xd8,
  0xff,0x00,0x56,0x2f,0x9a,0xc5,0xc2,0x03,0xad,0x57,0x4c,0x21,0x5d,0x8b,0x1d,0xa3,0x94,0x92,0x52,0xa0,
  0xdc,0x17,0x5d,0xb0,0x92,0x3f,0x5f,0x30,0x47,0x8e,0xf1,0x80,0x79,0x49,0x0a,0x81,0xd6,0x3c,0xbf,0xa5,
  0x0d,0x0b,0x45,0xae,0xf2,0x92,0xd9,0x32,0x7c,0xf6,0xf0,0x11,0x31,0x40,0x8c,0x1d,0xd9,0x5e,0x52,0x90,
  0x04,0xd1,0x18,0x50,0x7e,0x12,0x24,0x5f,0x55,0x79,0x7a,0xcb,0xb5,0xa1,0x41,0x00,0x3e,0x86,0x87,0x73,
  0x40,0x86,0xbb,0x59,0x12,0xcd,0x38,0x25,0x34,0x99,0x00,0x71,0x14,0xa0,0x40,0x0e,0xeb,0x85,0x82,0x7c,
  0xa8,0x25,0xf0,0x6c,0x42,0x18,0x22,0x0c,0xa7,0x4d,0x5a,0x73,0xe2,0x22,0xfa,0x44,0xab,0x22,0xcf,0x2a,
  0x8e,0x95,0x2b,0x52,0x7e,0x2e,0x85,0x3c,0x83,0xb3,0xde,0xb1,0x80,0xc2,0x10,0x7d,0xe3,0x6b,0x4f,0xec,
  0xfd,0xdb,0x58,0xf2,0x59,0xf0,0xe0,0x16,0x35,0xc6,0x04,0x1c,0x9c,0xe8,0x74,0x7f,0x6f,0xe2,0xbc,0x1b,
  0x86,0x62,0xf6,0xfa,0x0d,0xa2,0xb1,0x1b,0x86,0x1c,0x1d,0x31,0xe5,0x8e,0x65,0x66,0x26,0xea,0x30,0x46,
  0x4c,0xd0,0xca,0x12,0x20,0x1e,0xf0,0x39,0x16,0x65,0x3b,0x1b,0x2d,0xe7,0xa3,0xe1,0xb0,0xd5,0x38,0x39,
  0x3e,0x3b,0x03,0x63,0x0e,0xad,0xf0,0xd7,0xfd,0xbd,0x48,0x57,0xa8,0x16,0xf0,0xd8,0x72,0xd4,0x7c,0xb6,
  0xb3,0xae,0x49,0x6d,0x2e,0xdb,0x85,0xfc,0xc7,0x6b,0x20,0x7d,0xdf,0x7e,0x9b,0x61,0xf5,0xae,0x91,0x51,
  0x2d,0xc5,0x06,0xd8,0x4a,0x10,0x83,0x0d,0xae,0xa3,0x89,0xe3,0xb8,0x0b,0xc7,0xf0,0x50,0xb5,0xe2,0x5f,
  0xf9,0x4d,0x18,0x72,0x07,0x58,0x8a,0x0f,0xee,0x7a,0x58,0x23,0x51,0xf7,0xc5,0x37,0xf7,0xf7,0xf6,0xa5,
  0x81,0x0d,0xcf,0xd2,0xc2,0x69,0x02,0x8d,0xad,0xbe,0xbd,0xdf,0x98,0x71,0xdf,0x76,0x6c,0x27,0xc0,0xa1,
  0x5a,0x6b,0xd8,0xe8,0x15,0x6c,0xa5,0x86,0x60,0xc2,0x7a,0xa5,0xdb,0xe9,0x06,0x49,0x28,0x85,0xad,0x13,
  0xec,0x34,0x19,0x17,0x3b,0xf6,0x0b,0xc2,0x66,0xee,0x9c,0xb2,0x59,0x1e,0xbb,0x50,0x9d,0xef,0xaa,0x1a,
  0xc4,0x12,0x18,0x58,0xe8,0x26,0x58,0xff,0xc7,0x32,0x9f,0x27,0x15,0xed,0xf7,0x85,0x20,0xba,0x5c,0xee,
  0x30,0xf9,0x6b,0x01,0xc5,0xeb,0x91,0x42,0x15,0x70,0x29,0x87,0xaf,0x98,0x08,0xb1,0x06,0x30,0xaf,0x3e,
  0xbc,0x7b,0xbd,0x14,0xa7,0x20,0x7d,0x19,0x66,0x59,0xa2,0xa7,0xed,0xda,0x2f,0xe0,0x17,0xd2,0xda,0xdc,
  0x52,0x4b,0x64,0x4d,0x38,0x93,0x87,0x9c,0xeb,0xb9,0xa4,0x85,0x5a,0x76,0x0f,0x95,0x9a,0x92,0x04,0xf1,
  0x43,0xcb,0xfd,0xec,0x36,0x73,0x3f,0x06,0x72,0x82,0xd1,0x5e,0xaa,0x32,0x4f,0x59,0x82,0xaf,0xce,0x7e,
  0x65,0x8e,0xbf,0x81,0x5c,0x9c,0xaf,0xf5,0xa4,0x62,0x5f,0x7b,0xd8,0x1f,0x39,0x93,0xc9,0x64,0x18,0x6c,
  0xee,0x66,0x49,0x4a,0xf5,0x37,0x61,0x18,0x0e,0x95,0xb4,0x82,0xd4,0xcf,0x48,0xa5,0xbf,0x77,0x64,0x76,
  0x37,0x89,0x43,0xad,0x39,0x50,0xc4,0x40,0xaa,0xa9,0xf4,0x91,0xd2,0x54,0xdf,0x4f,0x66,0x05,0x51,0x28,
  0xf5,0xb0,0xa2,0xd2,0x44,0xf5,0x3b,0xc1,0x0b,0x42,0x75,0xf1,0x3e,0xc3,0x82,0x82,0x7c,0xc1,0x6c,0xc7,
  0x71,0xdb,0xe6,0x0e,0x27,0xd3,0xd6,0x5c,0xa1,0x31,0x72,0x85,0xa1,0xf5,0x0d,0x15,0xea,0x9a,0xac,0xe6,
  0x0a,0xec,0x5c,0xce,0x5e,0x7e,0x8b,0xe1,0x5c,0x5c,0xdf,0x06,0xc9,0xd6,0x64,0xc5,0x56,0xcc,0x24,0x2c,
  0x12,0xfe,0xe3,0xae,0xf3,0x2c,0xa2,0x3e,0x98,0xf0,0x0d,0x22,0x08,0xa6,0x5f,0x32,0x4f,0x97,0xed,0x5f,
  0x83,0x32,0xf3,0x65,0xe8,0x6f,0xbb,0x4a,0xee,0xfc,0x24,0x96,0xe2,0x84,0xa2,0x05,0x32,0xe5,0x37,0x06,
  0x43,0x9b,0x73,0x7f,0x6f,0xdb,0x1b,0xc8,0xe1,0xa0,0xc7,0xd0,0x97,0xe6,0xaa,0xd3,0xe2,0x58,0x1b,0x94,
  0xdf,0x5a,0x80,0x79,0x81,0xc7,0x97,0x32,0x35,0x42,0x8d,0x92,0xdc,0x85,0x9a,0x92,0xbd,0xf0,0xee,0x24,
  0xa7,0x43,0x4e,0x1c,0x43,0x16,0x0c,0x6d,0x2e,0x50,0x2d,0xe8,0x2f,0x7d,0xfb,0xae,0xf2,0x0f,0x0e,0xec,
  0x7d,0xe9,0x7e,0x79,0xb3,0xbc,0x62,0x50,0x3f,0xb9,0x6f,0xfb,0xcf,0x47,0x07,0x77,0x95,0x2d,0x58,0x71,
  0xc1,0x8f,0x28,0x3e,0xfd,0xd2,0x2f,0xc9,0x9d,0x5b,0x77,0x2f,0xe9,0x14,0xcd,0xf9,0xc2,0x2b,0xca,0x9c,
  0xe5,0x51,0x8e,0x13,0x82,0x4a,0xf3,0x6d,0x47,0x6b,0x84,0x89,0x6c,0xb3,0x23,0xd8,0x01,0x68,0xbd,0xbf,
  0x5f,0xa8,0x69,0x77,0xc3,0xb0,0x85,0x8a,0xc3,0x66,0x65,0x7e,0x67,0x75,0x18,0x04,0x59,0x96,0x5d,0x17,
  0x3e,0x88,0xd3,0x47,0x5b,0x79,0x67,0x0b,0x44,0xd1,0x70,0x07,0xa3,0x19,0x8d,0x17,0x29,0xe5,0x23,0x20,
  0x30,0xd6,0xbd,0x1c,0xed,0xf8,0xc0,0x09,0xf4,0xb3,0x84,0x86,0x64,0x08,0x15,0x21,0x80,0x18,0x99,0x59,
  0xc7,0x1d,0x0d,0x1b,0xbe,0x9a,0xd9,0x1b,0xb6,0x21,0x5c,0x6f,0x40,0xcf,0x36,0xce,0x20,0x3c,0xcf,0x33,
  0x5a,0x5c,0x88,0x1f,0x09,0x23,0x1b,0xf8,0x6a,0x8e,0xb5,0x28,0x53,0xf4,0x4d,0x17,0x65,0x1a,0xd6,0x9c,
  0x60,0xce,0xdd,0xe0,0x2b,0x95,0x7a,0x94,0x25,0x23,0x36,0xe7,0x2e,0xf9,0x25,0x02,0x27,0x90,0x09,0xc4,
  0x56,0x96,0xc7,0xb0,0xaa,0x9c,0x12,0x7b,0x7b,0xe2,0xc7,0x43,0x49,0xf5,0xfb,0xfb,0x87,0xfb,0xbc,0xfc,
  0xf0,0xfe,0xfd,0xeb,0x97,0x97,0x6f,0xdf,0xff,0xc5,0xd9,0xdb,0x5b,0x20,0x83,0xaa,0x03,0x9c,0xda,0x59,
  0xd9,0xbe,0x29,0x0a,0x1b,0xe5,0xe9,0xc2,0x81,0x71,0xbe,0xa8,0x04,0x98,0x40,0x3b,0x1a,0x0a,0x9a,0x3e,
  0xa2,0xec,0xeb,0x3e,0xac,0xf5,0x79,0x11,0x5b,0x0c,0x2a,0x52,0x8e,0xf0,0xa2,0x34,0xaf,0x68,0x5f,0x23,
  0xd8,0x66,0xc7,0xaa,0x4f,0x9e,0x60,0x6f,0x4c,0x4b,0x05,0x33,0xa8,0x55,0xf7,0x17,0x65,0xea,0x08,0xab,
  0xb5,0xbf,0xaf,0xdb,0x2d,0x81,0xad,0x18,0x15,0x74,0x6c,0x98,0xdd,0x55,0xd7,0x63,0xb7,0x37,0x6c,0x47,
  0x4e,0xed,0xe5,0x59,0x2e,0x4f,0x41,0xd6,0x8a,0x5c,0xb5,0xa7,0x28,0xa9,0xac,0x07,0x46,0x42,0xb1,0xcd,
  0x68,0x9a,0xe6,0xb6,0x2b,0x8f,0x15,0x37,0x4e,0xb0,0xd5,0x6b,0x7c,0x12,0xa6,0x98,0x5f,0x6f,0xe5,0x0f,
  0x0d,0x54,0x05,0x27,0x86,0x14,0xd4,0xb4,0x72,0x2a,0xda,0xde,0xad,0xd0,0x70,0xd8,0x4d,0xf9,0x91,0x42,
  0xb3,0xc9,0x15,0x81,0x94,0xc0,0x2b,0x14,0x13,0x14,0x33,0x54,0xc1,0x05,0x7c,0xad,0xb0,0x5f,0x8f,0x74,
  0xcc,0x78,0x0d,0x2d,0x39,0xf8,0x0f,0x2d,0x7f,0x55,0x77,0x55,0x15,0x6b,0x2a,0x2f,0x13,0x4b,0xab,0x31,
  0x7b,0x24,0x7d,0xd1,0xf5,0x23,0xa1,0x41,0x60,0x4e,0x68,0x40,0xe1,0x25,0xca,0xf6,0xde,0x1e,0xb6,0xf2,
  0x27,0x67,0xbd,0x9d,0xfc,0xe5,0x6a,0x5d,0x42,0x29,0x9a,0xf0,0x4d,0xc5,0x80,0x86,0xfc,0x6b,0x07,0x38,
  0x86,0xdc,0xbb,0x36,0xe5,0x3e,0x40,0xb0,0x31,0x51,0xd2,0x9d,0x75,0x91,0x49,0x03,0xe4,0xae,0xf2,0x3c,
  0xa5,0x24,0xb3,0xf7,0xf6,0xf4,0x0e,0x2a,0x7f,0x26,0xb7,0xe1,0xc9,0xe8,0xfe,0x69,0x3c,0x0d,0xd2,0x45,
  0xf2,0x14,0xc3,0x76,0xd4,0x4f,0x31,0xcd,0x8e,0x65,0x72,0x1b,0xf7,0xeb,0x4d,0xc9,0x08,0x6b,0xc9,0x78,
  0x98,0xa9,0xb5,0x5a,0x0f,0xbb,0xc9,0xc6,0xa8,0x1e,0x38,0xe0,0xa6,0xd2,0x91,0x3c,0xf0,0x88,0xce,0x01,
  0x00,0xa8,0x72,0x1e,0x12,0x59,0x4d,0xb7,0x29,0x45,0xf4,0x30,0xd2,0x71,0x52,0xe9,0xc2,0xa8,0x51,0x5a,
  0x61,0x81,0x5f,0x9f,0x4c,0xf3,0x8a,0x3d,0x5c,0x97,0xf2,0x82,0xdb,0x60,0x5e,0xbe,0x96,0x54,0xea,0x52,
  0x88,0x67,0xd7,0xdb,0xd4,0x94,0xf5,0xa6,0xb5,0x05,0xaa,0xe9,0x86,0xd1,0xdc,0xae,0x56,0xe8,0xac,0x0e,
  0xb2,0x20,0xcd,0x5b,0x37,0x63,0x55,0x9e,0xd9,0x94,0xe5,0xe8,0x39,0x3f,0x1e,0xed,0x4a,0xe6,0x91,0x12,
  0xf6,0xb0,0x20,0xad,0x37,0xdc,0x00,0xee,0xf2,0xf3,0xb5,0xfb,0xfb,0x7e,0x57,0xb2,0x79,0x6f,0x4f,0xa5,
  0x88,0xb9,0x56,0xc2,0x04,0x76,0x8d,0x0c,0xec,0xa8,0x3a,0x92,0xe3,0x87,0x7c,0x98,0x84,0x6a,0x24,0x96,
  0x71,0x54,0xeb,0xb0,0x0e,0x15,0x5a,0x3b,0xc6,0xd5,0x4f,0x3f,0x6b,0x32,0xe9,0x53,0x1a,0x07,0x7c,0xd2,
  0x5a,0xc6,0x34,0x65,0x24,0xd4,0xc8,0x38,0x30,0xba,0x09,0xd2,0x62,0xe4,0x02,0x33,0x41,0xef,0x49,0x38,
  0x5c,0x3e,0x1f,0xf2,0x3f,0x72,0x02,0xf9,0x0e,0x62,0x19,0xa1,0xb2,0x70,0x07,0xc0,0x81,0x33,0xe0,0xf1,
  0x7d,0x31,0x9d,0x89,0xb6,0xdd,0x11,0x99,0x2e,0xbb,0x2e,0xbb,0xf0,0xcd,0x45,0xba,0x88,0x97,0x5f,0xa3,
  0xed,0x22,0x60,0xbf,0x9e,0x19,0x23,0xd8,0x24,0x5b,0x70,0x77,0x5e,0x33,0x61,0x42,0x2b,0x29,0x7a,0xae,
  0x1f,0x05,0xb5,0x09,0xcc,0xaa,0x0d,0x8d,0x7b,0x5a,0x47,0xb6,0x35,0x98,0xc6,0xe9,0x29,0x97,0xca,0xfa,
  0xde,0x86,0xed,0xda,0xfa,0x2d,0x6b,0x4b,0xb0,0x8e,0x6d,0xf4,0x84,0x9b,0x1a,0xb6,0x6b,0xb7,0xaf,0x40,
  0x41,0x0d,0xab,0x07,0x65,0x5a,0x73,0xb2,0x82,0x3b,0x43,0xd6,0x22,0x63,0x49,0x8a,0xb5,0x84,0x90,0x19,
  0x16,0x95,0xd7,0x77,0x49,0x16,0xe7,0x77,0x1e,0x9e,0xaa,0x1b,0x99,0xb2,0x5a,0xf1,0x0a,0x11,0x7b,0xc8,
  0xd4,0x99,0x29,0x1b,0x81,0xe7,0xae,0x66,0x05,0xcc,0x0e,0x95,0x88,0xaf,0x95,0x15,0xd8,0xea,0xaf,0xeb,
  0x09,0x1c,0x59,0x8b,0x07,0xd5,0x47,0x96,0x56,0x60,0x84,0xdc,0xae,0x15,0x18,0x69,0xb4,0x37,0xab,0x8b,
  0x30,0xef,0x6a,0x9e,0xbd,0x78,0x3c,0x57,0xce,0x33,0x9c,0x78,0x56,0xb4,0xb7,0x57,0x9f,0x6b,0x39,0x32,
  0x65,0xce,0xb7,0x0c,0xfd,0x65,0x91,0x04,0x12,0x75,0xc9,0xb5,0x72,0x10,0x53,0x39,0x4f,0xf4,0xcf,0x65,
  0xeb,0x26,0x78,0x28,0x2e,0xe0,0x52,0xd9,0xa1,0x29,0xf6,0xf6,0xf8,0x86,0xd4,0x67,0x57,0xfd,0x76,0x6d,
  0x43,0x97,0x52,0x94,0xce,0x42,0xa7,0x2a,0x70,0x1c,0x65,0x21,0x92,0x69,0x5f,0x9d,0x86,0x21,0x17,0xd4,
  0xaf,0x76,0xac,0x1f,0xd0,0x76,0x08,0x33,0x64,0xd6,0x6d,0xf0,0xcf,0x1b,0xd4,0xe6,0xa3,0x36,0x35,0xda,
  0x27,0x0a,0x6c,0xd7,0x7e,0xa9,0x19,0x98,0x1f,0xfa,0xb6,0x51,0x35,0x59,0x9f,0x30,0xe3,0x8e,0xed,0x88,
  0x8c,0x03,0x1e,0x8a,0x85,0x26,0x56,0x17,0xe2,0x4c,0x02,0x17,0x85,0x1d,0x1c,0xdf,0xc6,0x13,0xb9,0xfa,
  0x9e,0x4c,0x0d,0x6e,0x97,0x7f,0xf0,0x96,0xa3,0xa4,0x2e,0xc5,0xd8,0x2e,0x1f,0xa8,0x26,0xc2,0x1b,0x26,
  0x55,0xb8,0x4e,0xe2,0x94,0xfa,0x36,0x97,0x93,0x8a,0x91,0x2c,0xbe,0x5a,0xd9,0x2e,0x14,0x0c,0xc8,0x46,
  0x2e,0x3c,0xb6,0xcb,0x96,0x3e,0x9c,0xe5,0xe3,0xa1,0xa3,0xc5,0xbf,0xe7,0x65,0xbb,0x8a,0x75,0xe1,0xf3,
  0x18,0xed,0xd7,0xe5,0x22,0xcb,0xf0,0x4d,0xa7,0x88,0xbb,0xe4,0x8e,0xdf,0xbd,0xfa,0x77,0x5d,0xa6,0x7d,
  0x5b,0xbf,0x91,0x55,0x34,0x45,0xbe,0x1e,0xf5,0xf2,0x7b,0x06,0xe9,0x4f,0xff,0x2e,0x12,0x27,0xbe,0x6d,
  0xd4,0xb4,0xd3,0x65,0x01,0x66,0xdb,0x76,0xe1,0x28,0xb3,0xa0,0x71,0x8b,0x2a,0x48,0x41,0xdf,0x6e,0xdd,
  0x42,0x82,0x11,0xa4,0xe4,0x24,0xf8,0x2c,0x7e,0x19,0xf5,0xa8,0x02,0xa4,0xe8,0xc0,0x7f,0x35,0x3a,0xd4,
  0x47,0xad,0x72,0x5a,0xd1,0xb2,0xb2,0xc1,0xa1,0x6a,0x6b,0x4d,0x9c,0xf9,0xa2,0x03,0x19,0x9f,0xef,0xec,
  0xd7,0x5a,0x09,0x7d,0xbb,0xbf,0xef,0xeb,0x72,0x74,0xd1,0xbd,0x1d,0xcd,0xf5,0x62,0x6e,0xaa,0xa5,0x84,
  0xcd,0x79,0x39,0x84,0xa4,0x92,0x07,0xe8,0x9e,0xed,0x9b,0x2e,0xb0,0x76,0x84,0x7c,0x61,0x8b,0x02,0x76,
  0xed,0xf2,0x66,0x3e,0x9d,0x5a,0x98,0x08,0x34,0x3f,0x2b,0x22,0x17,0x5f,0xb5,0xe0,0x75,0xb2,0x8c,0x2d,
  0xf4,0x55,0xab,0x97,0x51,0xb8,0xf4,0xf0,0xfc,0x04,0x2e,0xe6,0x55,0xb3,0x36,0xef,0x48,0x97,0x0e,0x6b,
  0x5a,0x24,0x3e,0x8a,0x92,0xf2,0x3a,0x8d,0x7e,0x5f,0x55,0x55,0xf4,0xbb,0xd8,0xa2,0x2e,0xaf,0x77,0xdc,
  0x4f,0x15,0xd2,0x05,0xeb,0xec,0xc6,0xce,0xb3,0x7e,0xbe,0x7c,0xf7,0x0b,0x5e,0xc8,0x31,0x29,0x04,0x3e,
  0x68,0x5d,0x62,0x6d,0x0b,0x8d,0xa5,0x2e,0x56,0x9a,0x0a,0xab,0xbe,0x7f,0x69,0xef,0xf7,0xc5,0x0e,0x4a,
  0x76,0x31,0xd7,0x23,0x45,0x17,0x6b,0xd0,0xb4,0xcd,0x47,0x98,0x72,0xf3,0x77,0x9b,0xa3,0xfe,0xf8,0xc7,
  0xff,0x81,0x13,0xc6,0x7f,0xfc,0x87,0x5d,0x2b,0x18,0x12,0xea,0x36,0x44,0xec,0x90,0x34,0x2f,0xeb,0x8d,
  0x3b,0xe7,0xef,0xe7,0x14,0x2a,0xa7,0x2b,0x68,0x52,0x15,0x3c,0xe6,0xcd,0x47,0x55,0x0e,0x44,0x3c,0xfd,
  0x50,0xdf,0x3d,0x71,0x1c,0x73,0xc4,0x0b,0xa8,0x4d,0x51,0x7d,0x49,0x75,0xd3,0xea,0x80,0x45,0x2a,0x75,
  0x8f,0xe2,0xae,0xd4,0x98,0x5c,0xbb,0x13,0x66,0xbb,0xe2,0x3c,0x95,0x78,0xda,0xf1,0xac,0x3a,0x5a,0x35,
  0x5a,0x45,0x7d,0x92,0x59,0xd5,0xa6,0xae,0x87,0x29,0x48,0x73,0x4f,0xb5,0x35,0xc1,0xb5,0x5f,0xb9,0xe3,
  0x0e,0x98,0xf5,0x65,0x31,0x0d,0x68,0xdd,0xd8,0x86,0xda,0x7a,0xd7,0x09,0xd6,0xb8,0x47,0xa6,0x2d,0x5c,
  0x9e,0xf4,0x6b,0xab,0x96,0x4d,0x08,0xc7,0x9a,0x57,0xdd,0x90,0x64,0x89,0x8e,0x06,0xab,0xa3,0x3e,0x54,
  0x01,0x6d,0xbd,0xd3,0x0b,0x06,0x1f,0x28,0x16,0x14,0x59,0x30,0xb5,0x9f,0xda,0xa9,0xb0,0xc0,0xae,0xde,
  0x5a,0x7e,0x9b,0x46,0x75,0x55,0xd4,0x8b,0xe4,0x2d,0x9c,0x9f,0x50,0x5e,0x9d,0x8b,0x56,0x93,0x3f,0xf7,
  0xf8,0x60,0xc5,0x4b,0xfc,0xaa,0x0d,0xb8,0xe4,0xfc,0x10,0x7e,0xee,0xb1,0xe5,0x97,0xfa,0xb5,0xbc,0x5d,
  0x53,0x77,0x50,0xb3,0x65,0x79,0x76,0x09,0x5d,0x2f,0xd4,0x4f,0x7f,0x8e,0xdf,0x7d,0xd3,0x86,0x37,0xee,
  0xd8,0x28,0x94,0xe7,0x5e,0xe3,0x0d,0x2f,0x00,0x6c,0x76,0xd7,0xa5,0x5e,0xcd,0xdb,0x1c,0x79,0xd1,0x6e,
  0xbb,0x00,0x9f,0xc6,0xf6,0xed,0xfc,0xc6,0x46,0xdf,0x42,0x54,0xe4,0xd5,0xd7,0x64,0x6c,0xb7,0xd6,0xb0,
  0xfa,0x52,0xdf,0x7e,0xb4,0x5d,0xdd,0xeb,0xe5,0x6d,0xed,0xec,0x3a,0x36,0x9b,0x9b,0x39,0x27,0x91,0x39,
  0x76,0x4e,0xa2,0xd6,0xc0,0x39,0x89,0xcc,0x51,0xf2,0x1a,0x8c,0xe2,0x2e,0x5d,0xcb,0x7c,0x12,0x2f,0x15,
  0x7b,0x75,0xbe,0xdc,0xd7,0x2b,0x89,0x3c,0x09,0x50,0x7a,0x8d,0xf2,0x79,0x37,0x0c,0xbb,0x46,0x5f,0xd8,
  0xd6,0x41,0x5d,0xcb,0x68,0x42,0xd8,0xb7,0xe5,0x51,0x0e,0xea,0x4f,0x13,0x71,0x7e,0x8f,0x48,0x13,0x5d,
  0xde,0xa0,0xc9,0x42,0xdd,0xf4,0x80,0x08,0xc8,0xbb,0x3d,0x26,0xe9,0x64,0x6b,0x8b,0x7e,0xf2,0x85,0x04,
  0x62,0x06,0x63,0xad,0x5c,0xa9,0x16,0x1d,0x69,0x59,0x1d,0x99,0x8e,0xea,0xb8,0xc7,0x50,0xa7,0x5b,0x1e,
  0xf5,0x97,0xb1,0xf0,0x7a,0xab,0xaf,0xac,0x2e,0x0f,0x99,0xd9,0xa4,0x8e,0x70,0x11,0xf9,0x51,0x5e,0x19,
  0xea,0x8c,0x13,0xdf,0xe7,0xea,0xba,0x51,0xfb,0x32,0xbf,0xfe,0xc5,0x05,0xee,0x97,0x3f,0x6e,0x34,0xdb,
  0x96,0xd0,0xbe,0x78,0xd0,0xa7,0xe7,0xb4,0x81,0x78,0xcb,0x88,0xb3,0x3a,0x93,0x79,0x8d,0x43,0x73,0xfd,
  0xe6,0xd4,0x03,0x19,0xa4,0xcd,0x0e,0xa9,0x56,0x59,0x64,0xa9,0xfd,0x82,0xc3,0xa5,0x8e,0x63,0xec,0xd0,
  0xfe,0xcb,0xeb,0x4b,0xbb,0x79,0x98,0x8d,0x69,0x78,0x3c,0xf4,0xac,0x6f,0x95,0xf4,0x1d,0x99,0x0c,0xd9,
  0x72,0xec,0xa9,0x1d,0x23,0xe2,0x31,0x61,0xdf,0x71,0xbf,0xa7,0x4a,0x87,0x67,0x3b,0xc5,0xd9,0x9c,0xc8,
  0x06,0x87,0xe8,0xa9,0x59,0x53,0x0a,0x49,0x4f,0xc4,0x7a,0x2d,0x8e,0x0b,0x23,0x12,0xcd,0xa8,0x6f,0x67,
  0xf9,0x00,0x15,0x95,0xbd,0xfd,0x94,0x93,0x7f,0xef,0xad,0xf2,0x61,0x89,0x17,0x6b,0x5b,0xfe,0xef,0x38,
  0x97,0xab,0x02,0xdc,0x18,0x14,0x5f,0x7e,0x74,0x76,0xf0,0xd7,0x2a,0xcf,0xec,0x8d,0xbf,0xc8,0x62,0x3a,
  0x4d,0x32,0xca,0x8f,0xf8,0xf9,0xb8,0xae,0x33,0xc9,0xba,0x23,0x24,0xfc,0x5b,0x39,0x74,0x8e,0xba,0x5c,
  0x89,0x07,0xc0,0xfb,0x2a,0x3f,0xf6,0xa4,0x60,0xbf,0xce,0x90,0x07,0x1b,0xe0,0x15,0x05,0x2b,0xbf,0x11,
  0xfe,0xd2,0x13,0x2b,0x30,0x9e,0x56,0x7c,0xa1,0xc0,0x57,0x0f,0x15,0x5f,0x34,0x7a,0x05,0x7c,0x25,0xd8,
  0x4d,0x66,0x9b,0x39,0x21,0x36,0x53,0xf8,0x74,0x45,0xba,0x32,0x4f,0x0a,0x55,0x1d,0xd4,0xa6,0xc5,0xa1,
  0xe5,0x9f,0xe5,0x4e,0x31,0xbb,0x5e,0xa2,0x76,0xf1,0xc4,0xe2,0x0d,0x7f,0x8b,0x78,0xb4,0x3a,0x76,0x9d,
  0x89,0x42,0x4e,0x8f,0xac,0x42,0x60,0xe2,0xf6,0x62,0x4b,0x27,0xe0,0x97,0xb7,0x34,0x69,0x81,0x5b,0x5c,
  0x2e,0x0e,0xea,0x10,0x54,0x78,0xd9,0x17,0x09,0xa7,0x5a,0x3b,0xac,0xd5,0x64,0xfa,0x71,0xc8,0xc1,0x81,
  0xf5,0x4a,0x7e,0x68,0xca,0xd5,0x0e,0x74,0xf9,0xde,0x1c,0xa8,0x3c,0x31,0xcf,0x49,0x83,0x7a,0x13,0xdf,
  0x16,0xc4,0xe4,0xb5,0x67,0xbd,0xca,0xb1,0x4e,0xe3,0x6f,0x0b,0xba,0xa0,0x16,0x41,0x78,0x3c,0xcc,0xf9,
  0xf9,0xf2,0xf2,0xa3,0x62,0x11,0x8a,0x5f,0xed,0x51,0x1f,0x1b,0xc8,0x4b,0xee,0xc2,0x93,0x8c,0xa5,0x2b,
  0x0b,0xf6,0x7f,0x71,0x3d,0xcb,0x17,0xcc,0x22,0xe2,0xa3,0x00,0x69,0x4e,0x32,0x0f,0xf1,0x97,0x77,0x4e,
  0x3a,0x93,0xbf,0xfa,0x3e,0xed,0xed,0x69,0x17,0x44,0x94,0xd6,0x30,0xb2,0xd1,0xda,0xfd,0x39,0xe7,0x5c,
  0xdc,0xd2,0x81,0x5d,0x57,0x84,0xc1,0x52,0xbf,0x9a,0x36,0x42,0x1e,0xf0,0xf0,0x50,0xbf,0x0b,0x17,0x34,
  0xef,0xd0,0x75,0x31,0x93,0xa6,0x8b,0x0c,0x61,0xe6,0x0c,0x62,0x1f,0x90,0x22,0x39,0x10,0x47,0x4f,0x2e,
  0xe7,0xd1,0x5a,0x6b,0x98,0xf0,0x79,0xd9,0x1e,0x62,0x11,0x1a,0x78,0x38,0xe6,0xc9,0x8e,0x4a,0xbe,0xe9,
  0x86,0x40,0xbb,0x25,0x25,0x83,0x29,0x41,0xd3,0xee,0x20,0xdd,0xb3,0x5a,0x39,0x50,0xbe,0xf5,0xfc,0x2c,
  0xc2,0xf6,0xed,0x17,0x90,0xc8,0x48,0x2a,0xcc,0x41,0xc8,0x3b,0xee,0x49,0x25,0xc2,0x3a,0xb8,0x8a,0x2b,
  0xef,0xd6,0xcb,0x12,0x1e,0x3e,0xd0,0xf1,0x6d,0xb4,0xea,0x9e,0xd5,0x1d,0x86,0xda,0x28,0xd0,0x96,0x71,
  0x3a,0xb5,0x6d,0xdd,0x6d,0xcf,0xa1,0xd6,0x15,0x1d,0xf7,0x1b,0xb7,0xd2,0x4f,0x6d,0xbc,0xe1,0x77,0x5c,
  0x1c,0x0f,0x87,0xbe,0x2c,0x25,0x30,0xb2,0xb9,0x24,0xe6,0x19,0x45,0x55,0xd5,0x1f,0x85,0xeb,0x4d,0xb0,
  0xa5,0x0c,0x58,0xaa,0xd3,0x34,0x84,0xea,0x5f,0x4c,0x1a,0x54,0x37,0xf6,0x85,0x56,0xee,0xeb,0x8b,0x66,
  0x08,0x1a,0x2f,0xf4,0x12,0x5f,0xf1,0x42,0x2f,0xdc,0xbd,0xd0,0x8b,0x7b,0x7d,0x59,0x4d,0x4a,0x53,0x0f,
  0xbf,0xfa,0xf0,0x6f,0xa0,0xf9,0x13,0xb8,0x4a,0x71,0x7f,0x4f,0x53,0x51,0xfa,0x0b,0x17,0x34,0xda,0x39,
  0xe1,0x97,0xf8,0x95,0x08,0x7b,0xbf,0x6f,0x16,0xb0,0xdb,0xfc,0x76,0x7c,0xeb,0x13,0x9a,0x36,0x56,0xa4,
  0xe3,0x5b,0xf9,0xb9,0x45,0x9b,0x97,0x97,0xf3,0x36,0xf9,0x7d,0x40,0xdb,0xa8,0x13,0xc7,0x77,0x32,0x73,
  0x11,0xf1,0x4b,0x57,0xaa,0xb0,0x5b,0xbe,0xd4,0x3f,0x3c,0x62,0xbb,0xed,0xcb,0x7b,0xd8,0xaf,0xf3,0x7b,
  0x64,0xf6,0x06,0x8b,0xa7,0xf7,0x6d,0xe0,0x1a,0x2c,0xa4,0x96,0x17,0xa1,0xe4,0xe2,0x39,0x79,0x9a,0x97,
  0x53,0x78,0xcd,0xf5,0xf6,0x3c,0xb9,0xf8,0x2c,0x97,0x27,0xcd,0xe5,0x57,0xb8,0x97,0xe7,0xc2,0x87,0xc7,
  0xbe,0x79,0xf2,0x73,0x26,0xfd,0xa8,0x23,0xd8,0xdc,0x46,0xe6,0xad,0x2b,0xf0,0xea,0x4a,0x99,0xa8,0xad,
  0xc0,0xc5,0x7d,0x5c,0xbc,0xb4,0xc7,0x13,0x8b,0xd7,0x4d,0x75,0xae,0x6e,0x44,0xdc,0xdf,0xd7,0x8d,0x7b,
  0x7b,0x30,0x62,0x57,0xbe,0x32,0x0f,0xc2,0xf0,0x0a,0x61,0x7d,0xdc,0xb5,0xae,0x93,0xd4,0xfc,0x06,0x1b,
  0xcf,0xeb,0x37,0x2e,0xa2,0x99,0x03,0x01,0x66,0x3d,0xae,0xe3,0x38,0x09,0xbb,0xe0,0x65,0x1e,0x43,0x79,
  0xee,0xef,0x1b,0xea,0xb3,0xcb,0xc2,0x99,0x62,0x7b,0x21,0xfd,0xbf,0xa0,0x35,0x7f,0xeb,0xae,0x72,0xdd,
  0xb7,0x26,0x0e,0x0c,0x69,0x1f,0x89,0xd6,0x5a,0xd1,0x00,0x79,0x81,0x29,0x53,0x2d,0x05,0x67,0x35,0xbf,
  0xa1,0xa6,0x9d,0xf4,0x48,0xe7,0xe5,0x8f,0xbf,0xff,0xb7,0xed,0x9b,0x24,0xbd,0xb0,0xc5,0x11,0xed,0x16,
  0x48,0x52,0x59,0xea,0x0c,0x81,0x60,0x6c,0xfc,0x28,0x1c,0xd7,0xa7,0xfc,0xbb,0x70,0xd0,0x5c,0x27,0xba,
  0x1e,0xf3,0x5b,0x82,0xf6,0xfd,0xed,0x7a,0x08,0xa4,0x28,0xca,0xd5,0x5a,0x55,0x1c,0x6e,0x35,0x46,0xe2,
  0x92,0x28,0x9e,0xeb,0x23,0xcb,0xd9,0x17,0xf2,0x07,0x2e,0xd4,0x71,0xed,0x8f,0x1f,0x3e,0x5f,0xda,0x6e,
  0x63,0xd5,0x6b,0x75,0xe2,0xe7,0xf3,0xee,0x86,0xb3,0x23,0x55,0xef,0x6e,0x43,0xf5,0x1a,0x55,0x1d,0x4d,
  0xd6,0xdc,0xb1,0x2c,0xe3,0xec,0xd7,0xbc,0x33,0xd0,0x96,0xb5,0xad,0x85,0x44,0x9e,0x3c,0x35,0x27,0xd7,
  0x04,0x3e,0x6f,0x35,0x05,0xbf,0xb5,0x11,0xa3,0xf1,0xef,0xb9,0xf0,0x04,0x67,0x5d,0x8e,0x52,0x1f,0x09,
  0x75,0x9e,0x8a,0xb7,0x90,0xa8,0x8f,0x4e,0xc0,0x4b,0x6e,0xcc,0x10,0x27,0x31,0x37,0x85,0x78,0xe1,0x84,
  0x7f,0x65,0x4b,0xc0,0x92,0xf3,0xd6,0xc7,0xd4,0xe6,0x4c,0x5d,0xb7,0x45,0x77,0x2c,0x6b,0x63,0x12,0x4e,
  0xec,0x93,0xbc,0x69,0xc8,0x83,0xc3,0xf6,0x55,0x43,0x7e,0x65,0x42,0xb1,0x02,0xcf,0x66,0xd7,0x69,0x17,
  0x0c,0xe8,0xfd,0x07,0x1c,0x95,0x47,0xb7,0x53,0xf8,0x23,0x22,0x89,0xd3,0xbd,0xb9,0x7c,0x6e,0x74,0x18,
  0xe3,0xb0,0x79,0xe8,0xbe,0xe5,0xca,0x6c,0x32,0xed,0xf3,0x01,0x5a,0x9d,0x89,0x68,0x08,0x36,0xcd,0x69,
  0xf2,0xc2,0xde,0xdb,0x43,0x14,0xe4,0x26,0xb6,0x59,0x06,0x25,0x3e,0x31,0x3e,0x16,0x03,0xdc,0x22,0xeb,
  0x76,0xf1,0x35,0xf2,0x8c,0xd8,0x9f,0x87,0x75,0x47,0x01,0x63,0xb7,0xb8,0x35,0x2d,0x25,0xf1,0xcf,0x79,
  0x5d,0x9f,0x85,0x66,0xb0,0x44,0xb6,0x08,0x22,0x77,0xf8,0xdf,0x8c,0x10,0xbd,0xcd,0x93,0xbc,0xa6,0x75,
  0x6b,0x33,0xee,0xef,0x4d,0xdd,0xaa,0x9f,0x5b,0x36,0x58,0x6b,0x6f,0xaf,0x19,0xc7,0x3d,0xa9,0x78,0x08,
  0x6e,0x94,0xac,0x3b,0xdc,0xb5,0x47,0x74,0xf1,0x1d,0x69,0x6d,0xcd,0x65,0x4b,0x6a,0x1b,0x9f,0x76,0xb1,
  0xfd,0x6d,0x48,0x6c,0x78,0xdd,0x3e,0xba,0x87,0x5b,0x89,0x63,0x7e,0x2e,0x23,0xe8,0xfe,0x24,0xc6,0x23,
  0xd9,0x2d,0x33,0x90,0xd8,0x80,0xf7,0x08,0xd9,0x1f,0xb1,0x75,0x76,0xd7,0x4d,0x52,0xfe,0x81,0x50,0xdb,
  0x95,0x55,0x78,0xbc,0x58,0x0e,0x8a,0x1f,0x69,0xc6,0x5e,0xf1,0x2b,0x8c,0x2a,0x98,0xe0,0x5e,0x81,0xdc,
  0x12,0x57,0x77,0x48,0xff,0x89,0xc2,0xae,0x8d,0xa3,0x5f,0xfa,0x6c,0xa3,0x16,0xa5,0x49,0x74,0xc3,0xaf,
  0xfe,0xaa,0xa9,0x65,0x85,0x8d,0x76,0x5b,0xf3,0xa9,0x03,0xd1,0x21,0x09,0x76,0x2a,0xca,0xa4,0xe3,0xc4,
  0xbf,0x64,0x63,0x92,0x14,0xf4,0xaf,0x16,0xa6,0x19,0xf7,0x76,0xa0,0x5a,0xb1,0xf9,0x19,0x00,0xd1,0x0f,
  0xf3,0x99,0x2a,0x0f,0x2a,0x3e,0x2f,0xaa,0x27,0xfd,0x54,0x42,0x15,0x68,0xa0,0x7d,0x2b,0x40,0x65,0x3d,
  0xeb,0x4f,0x14,0xd5,0x07,0x38,0xaa,0x2b,0xd7,0x7c,0xdb,0x02,0x4c,0x8e,0x83,0xf9,0x05,0x12,0x67,0xa2,
  0x02,0xcc,0xbd,0x3d,0x23,0xbc,0x30,0x4a,0x23,0x74,0xd1,0xd0,0xd4,0x53,0xfd,0x25,0xa5,0xac,0xae,0xb6,
  0xc6,0x6a,0x31,0x50,0x0a,0x08,0xd9,0x03,0x6a,0x6e,0xdc,0xf1,0x31,0x7c,0x38,0x42,0xd4,0x9f,0xb4,0xb7,
  0x02,0x02,0xb1,0x59,0x02,0xee,0x39,0xd2,0x9a,0xd3,0x31,0xbf,0xcb,0x68,0x1c,0x6e,0xfb,0x9a,0x43,0xa0,
  0x6b,0x01,0xec,0xea,0x3c,0xe0,0xe9,0xd5,0x55,0xc1,0xcd,0xea,0x3b,0x71,0x63,0x44,0x5b,0x15,0xd7,0x71,
  0xaa,0xdc,0x4e,0x7e,0x28,0x44,0x16,0xf8,0x42,0xd1,0xfd,0x53,0xae,0xc1,0xf3,0xf4,0x46,0xb0,0xb3,0x71,
  0xe0,0xef,0xf3,0x03,0xf9,0x99,0xa4,0xf3,0x03,0xf1,0xdf,0x5d,0x1c,0xf0,0xff,0x4a,0xfb,0xff,0x03,0xda,
  0xa1,0xf4,0x64,0x5b,0x7b,0x00,0x00
};


// ===== DirectApplication.h =====
#include <Arduino.h>
#include <math.h>
#include <stdlib.h>


extern "C" {
#include <user_interface.h>
extern uint8_t chip6_phy_init_ctrl[];
}
#define Serial IQSocket
static constexpr uint32_t BASE=0x3ffe8000,LAYOUT=0x3ff20e4c,CPU_CLOCK=0x3ff00014;
static constexpr uint32_t CPU_MHZ=160,MAX_WORDS=2048;
static constexpr bool ENABLE_FINE_TUNE=true;
static bool ready,lastValid,pbusKnown,macKnown,pllOffsetNeedsReset,captureBusySafe;
static uint16_t lastWords,activeFrequencyMHz,requestedFrequencyMHz;
static uint8_t activeChannel,manualGain,receiverMac[6];
static uint32_t serialBaud,configuredPaceUs,transmitErrors,lastPbus21,lastPbus31,lastPbus32;
static int32_t activePllOffset;
static IqResult result;
struct PayloadCursor {uint16_t word;uint8_t held;uint32_t accumulator;};
static uint32_t rd(uint32_t a){return *reinterpret_cast<volatile uint32_t*>(a);}
static void invalidate(IqStatus c){lastValid=false;lastWords=0;result={};result.code=c;}
static int16_t iqSigned10(uint32_t x){return WebSdrCapture::signed10(x);}
static void iqDecode(uint32_t x,int16_t&a,int16_t&b){WebSdrCapture::decode(x,a,b);}
static bool profileIsValid(){const auto&s=WebSdrCapture::status();return s.profile&&s.radioRestored;}
static bool iqTuneFrequency(uint16_t mhz){
  requestedFrequencyMHz=mhz;
  const bool ok=WebSdrCapture::configure(mhz,manualGain);
  result=WebSdrCapture::lastResult();lastValid=false;lastWords=0;ready=ok;
  DirectSession::captureValid=false;DirectSession::captureCode=uint8_t(result.code);
  if(ok){activeFrequencyMHz=mhz;activeChannel=uint8_t(1u+(uint32_t(mhz)-2412u+2u)/5u);activePllOffset=0;}
  return ok;
}
static bool iqSetGain(uint8_t gain){manualGain=gain;return iqTuneFrequency(requestedFrequencyMHz);}
static bool iqCapture(uint16_t n){
  captureBusySafe=false;
  ++DirectSession::captures;
  DirectSession::captureValid=false;
  const uint32_t started=micros();
  if(!DirectSession::powerSave(true)){
    // The AP may have received PM1 even if its ACK was missed. Attempt PM0
    // without capturing, while preserving any still-pending SDK frame.
    DirectSession::powerSave(false);
    DirectSession::captureWindowUs=micros()-started;
    ++DirectSession::captureFailures;invalidate(IqStatus::PowerSaveControl);
    DirectSession::captureCode=uint8_t(result.code);return false;
  }
  // No artificial sleep dwell: capture as soon as the NULL PM1 TX completes.
  const bool captured=WebSdrCapture::capture(n);
  const bool resumed=DirectSession::powerSave(false);
  const bool stable=captured&&WebSdrCapture::verifyBufferHash();
  DirectSession::captureWindowUs=micros()-started;
  result=WebSdrCapture::lastResult();const auto&s=WebSdrCapture::status();
  lastPbus21=s.beforePbus[0];lastPbus31=s.beforePbus[1];lastPbus32=s.beforePbus[2];pbusKnown=true;
  lastWords=WebSdrCapture::count();lastValid=captured&&resumed&&stable;
  if(!lastValid){
    ++DirectSession::captureFailures;result.valid=false;
    if(!resumed)result.code=IqStatus::PowerSaveControl;
    else if(captured&&!stable)result.code=IqStatus::Overrun;
  }
  captureBusySafe=!captured&&resumed&&result.code==IqStatus::Busy&&s.rfRestoreVerified&&
    s.radioRestored&&!s.busy&&!s.rxSessionActive&&s.rxSessionRestored&&!DirectSession::latchedFault&&WiFi.status()==WL_CONNECTED;
  DirectSession::captureValid=lastValid;DirectSession::captureCode=uint8_t(result.code);
  return lastValid;
}
static uint16_t currentFrequency() {
  return activeFrequencyMHz;
}

static uint32_t effectivePaceUs() {
  return 0;
}

static void finishTextChunk() {
  // The WebSocket adapter polls and yields once, without UART pacing.
  Serial.flush();
}

static void printStatus() {
  const bool profile = ready && profileIsValid();
  // Keep every formatted write below 100 bytes, including worst-case numbers.
  // The tested USB/UART route lost bytes at high baud without pacing.
  // Flush/pace between fragments; exactly one LF terminates the JSON object.
  Serial.printf("STAT {\"seq\":%u,\"n\":%u,\"valid\":%s,\"code\":%u,",
    result.sequence, result.requested, result.valid ? "true" : "false",
    unsigned(result.code));
  finishTextChunk();
  Serial.printf("\"ready\":%s,\"profile\":%s,\"guards\":%u,\"beyond\":%u,",
    ready ? "true" : "false", profile ? "true" : "false", result.guards, result.beyond);
  finishTextChunk();
  Serial.printf("\"changed\":%u,\"cycles\":%u,\"low\":%u,",
    result.changed, result.cycles, unsigned(result.sawLow));
  finishTextChunk();
  Serial.printf("\"armed\":%u,\"done\":%u,\"status\":%u,\"after\":%u,",
    result.armed, result.done, result.status, result.after);
  finishTextChunk();
  Serial.printf("\"A\":%lld,\"B\":%lld,\"E\":%lld,", result.sumA, result.sumB, result.energy);
  finishTextChunk();
  Serial.printf("\"heap\":%u,\"freq\":%u,\"gain\":%u,",
    ESP.getFreeHeap(), unsigned(currentFrequency()), unsigned(manualGain));
  finishTextChunk();
  Serial.printf("\"requestedFreq\":%u,\"baseChannel\":%u,\"xtal\":%u,\"offset1024\":%d,",
    unsigned(requestedFrequencyMHz), unsigned(activeChannel),
    unsigned(chip6_phy_init_ctrl[1]), int(activePllOffset));
  finishTextChunk();
  Serial.printf("\"pllOffsetNeedsReset\":%s,\"extfreq\":%s,",
    pllOffsetNeedsReset ? "true" : "false", ENABLE_FINE_TUNE ? "true" : "false");
  finishTextChunk();
  Serial.printf("\"pbus\":[%u,%u,%u],\"pbusKnown\":%s,",
    lastPbus21, lastPbus31, lastPbus32, pbusKnown ? "true" : "false");
  finishTextChunk();
  // Legacy STAT key "saved" is retained and now aliases BANK0.
  Serial.printf("\"data\":\"0x%08x\",\"saved\":\"0x%08x\",",
    unsigned(uintptr_t(&iqStorage.words[0])), unsigned(uintptr_t(&iqStorage.words[0])));
  finishTextChunk();
  Serial.printf("\"layout\":%u,\"cpuReg\":%u,\"baud\":%u,\"txErrors\":%u,",
    rd(LAYOUT), rd(CPU_CLOCK), serialBaud, transmitErrors);
  finishTextChunk();
  Serial.printf("\"paceUs\":%u,\"paceConfiguredUs\":%u,",
    effectivePaceUs(), configuredPaceUs);
  finishTextChunk();
  Serial.printf("\"macKnown\":%s,\"mac\":\"%02x:%02x:%02x:%02x:%02x:%02x\"}\n",
    macKnown ? "true" : "false", unsigned(receiverMac[0]), unsigned(receiverMac[1]),
    unsigned(receiverMac[2]), unsigned(receiverMac[3]), unsigned(receiverMac[4]),
    unsigned(receiverMac[5]));
  finishTextChunk();
}

static uint32_t crc32Byte(uint32_t crc, uint8_t value) {
  return FastCrc32::updateByte(crc,value);
}

static size_t fillPayload(PayloadCursor &cursor, uint16_t n, bool raw,
                          uint8_t *bytes, size_t capacity) {
  size_t used = 0;
  while (used < capacity) {
    if (!raw && cursor.held == 0 && cursor.word+1u < n && capacity-used >= 5u) {
      // Two little-endian 20-bit samples occupy exactly five bytes. Reading
      // each volatile capture word once avoids five byte-at-a-time cursor
      // iterations without changing a bit of the CAP20 wire representation.
      const uint32_t a = iqStorage.words[cursor.word++] & 0xfffffu;
      const uint32_t b = iqStorage.words[cursor.word++] & 0xfffffu;
      bytes[used++] = uint8_t(a);
      bytes[used++] = uint8_t(a >> 8);
      bytes[used++] = uint8_t((a >> 16) | (b << 4));
      bytes[used++] = uint8_t(b >> 4);
      bytes[used++] = uint8_t(b >> 12);
      continue;
    }
    if (cursor.held < 8) {
      if (cursor.word < n) {
        // CAP20: append one 20-bit A/B word to a little-endian bit stream.
        // RAW: append an unmodified 32-bit word. held is always zero then.
        const uint32_t word = iqStorage.words[cursor.word++];
        cursor.accumulator |= (raw ? word : word & 0xfffffu) << cursor.held;
        cursor.held += raw ? 32 : 20;
      } else {
        if (cursor.held) {
          // An odd CAP20 sample count leaves four low bits; high bits are zero.
          bytes[used++] = uint8_t(cursor.accumulator);
          cursor.accumulator = 0;
          cursor.held = 0;
        }
        break;
      }
    }
    bytes[used++] = uint8_t(cursor.accumulator);
    cursor.accumulator >>= 8;
    cursor.held -= 8;
  }
  return used;
}

static uint32_t payloadCrc(uint16_t n, bool raw) {
  PayloadCursor cursor = {};
  uint8_t bytes[512];
  uint32_t crc = 0xffffffffu;
  size_t count;
  while ((count = fillPayload(cursor, n, raw, bytes, sizeof(bytes))) != 0) {
    for (size_t i = 0; i < count; ++i) crc = crc32Byte(crc, bytes[i]);
    yield();
  }
  return crc ^ 0xffffffffu;
}

static bool sendPayload(uint16_t n, bool raw) {
  PayloadCursor cursor = {};
  uint8_t bytes[512];
  size_t count;
  while ((count = fillPayload(cursor, n, raw, bytes, sizeof(bytes))) != 0) {
    if (Serial.write(bytes, count) != count) {
      ++transmitErrors;
      // Do not insert an error line inside an already-started binary packet.
      // The receiver detects truncation, times out and sends a fresh SYNC.
      return false;
    }
    // No printing here: only wait for the binary chunk to drain, then pace.
    finishTextChunk();
  }
  // Protocol contract: no newline, END marker or other byte after the payload.
  return true;
}

static void capturePacket(uint16_t n) {
  if (!iqCapture(n)) {
    if(captureBusySafe)Serial.print("ERR BUSY restored=1 awake=1 intact=1\n");
    else Serial.printf("ERR capture %u\n", unsigned(result.code));
    return;
  }
  const uint32_t crc = payloadCrc(lastWords, false);
  // cycles measures trigger-to-DONE at the checked CPU clock of 160 MHz.
  // It does not include validation, encoding or UART transfer.
  const uint32_t captureUs = (result.cycles + CPU_MHZ - 1u) / CPU_MHZ;
  Serial.printf("DATA %u %08x %u\n", unsigned(lastWords), crc, captureUs);
  sendPayload(lastWords, false);
}

static void rawPacket() {
  if (!lastValid || !lastWords) {
    Serial.print("ERR no valid capture\n");
    return;
  }
  const uint32_t crc = payloadCrc(lastWords, true);
  Serial.printf("BIN %u %08x\n", unsigned(lastWords), crc);
  sendPayload(lastWords, true);
}

// ---- Optional post-capture spectrum: ZOOMFFT / ZCAP -------------------------
// The legacy INFO identity, CAP20/RAW? packets and acquisition routines remain
// unchanged. ZCAP is one request/one reply; it never enables a persistent mode.
//
// ZCAP <samples> <fft> <first> <count>
//   fft = 512/1024/2048; samples <= 2048, a positive multiple of fft.
//   first/count select bins in the browser's FFTshift order (Q is negated).
// ZDATA1 <samples> <fft> <first> <count> <seq> <crc> <captureUs> <processUs> <clips>\n
//   followed by exactly count bytes, with no trailing delimiter.
//   dBFS10 = -140 + byte * 5/8. Values are rounded to nearest, then clamped;
//   code 0 also represents everything below the encoding floor.
//   CRC32 covers the payload only, as in CAP20. processUs covers post-capture
//   allocation, DSP and CRC, excluding the UART reply; clips counts pairs.
//
// No allocation or DSP occurs until iqCapture() has returned successfully.
// V6 reads BANK0 directly. The motor is disarmed and the normal interrupt
// state restored. All pacing stays at its configured value.
// Keep constants in flash: no initialized writable global may precede iqStorage.
static const int32_t ZOOM_FFT_ROOTS[11][2] PROGMEM = {
  {-1073741824, 0},          // exp(-j*2*pi/2), Q30
  {0, -1073741824},          // 4
  {759250125, -759250125},    // 8
  {992008094, -410903207},    // 16
  {1053110176, -209476638},   // 32
  {1068571464, -105245103},   // 64
  {1072448455, -52686014},    // 128
  {1073418433, -26350943},    // 256
  {1073660973, -13176464},    // 512
  {1073721611, -6588356},     // 1024
  {1073736771, -3294193},     // 2048
};
static const int32_t ZOOM_HANN_ROOTS[3][2] PROGMEM = {
  {1073660656, 13202248},     // exp(j*2*pi/(512-1)), Q30
  {1073721572, 6594796},      // 1024
  {1073736766, 3295803},      // 2048
};

static int32_t zoomRoundQ30(int64_t value) {
  // Division (rather than a signed right shift) defines negative rounding too.
  const int64_t half = int64_t(1) << 29;
  return int32_t((value + (value < 0 ? -half : half)) / (int64_t(1) << 30));
}

static void zoomFft(int32_t *re, int32_t *im, uint16_t n) {
  for (unsigned i = 1, j = 0; i < n; ++i) {
    unsigned bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) {
      const int32_t r = re[i], q = im[i];
      re[i] = re[j]; im[i] = im[j];
      re[j] = r; im[j] = q;
    }
  }
  unsigned stage = 0;
  for (unsigned len = 2; len <= n; len <<= 1, ++stage) {
    const int32_t cr = int32_t(pgm_read_dword(&ZOOM_FFT_ROOTS[stage][0]));
    const int32_t ci = int32_t(pgm_read_dword(&ZOOM_FFT_ROOTS[stage][1]));
    int32_t wr = int32_t(1) << 30, wi = 0;
    const unsigned half = len >> 1;
    // Generate each twiddle only once per stage, then reuse across its groups.
    for (unsigned j = 0; j < half; ++j) {
      for (unsigned k = j; k < n; k += len) {
        const unsigned l = k + half;
        const int32_t tr = zoomRoundQ30(int64_t(re[l]) * wr - int64_t(im[l]) * wi);
        const int32_t ti = zoomRoundQ30(int64_t(re[l]) * wi + int64_t(im[l]) * wr);
        const int32_t ar = re[k], ai = im[k];
        // Scale every stage by 1/2. Wide intermediates avoid signed overflow.
        re[k] = int32_t((int64_t(ar) + tr) / 2);
        im[k] = int32_t((int64_t(ai) + ti) / 2);
        re[l] = int32_t((int64_t(ar) - tr) / 2);
        im[l] = int32_t((int64_t(ai) - ti) / 2);
      }
      const int32_t next = zoomRoundQ30(int64_t(wr) * cr - int64_t(wi) * ci);
      wi = zoomRoundQ30(int64_t(wr) * ci + int64_t(wi) * cr);
      wr = next;
    }
    yield(); // Post-capture work only; never inside the acquisition IRQ mask.
  }
}

static void zoomSpectrum(uint16_t nSamples, uint16_t nFft,
                         uint16_t firstBin, uint16_t binCount,
                         int32_t *re, int32_t *im, float *power,
                         uint8_t *payload, uint16_t &clipped) {
  const int32_t scale = int32_t(1) << 20;
  const int32_t one = int32_t(1) << 30;
  const unsigned windowIndex = nFft == 512 ? 0 : nFft == 1024 ? 1 : 2;
  const int32_t cr = int32_t(pgm_read_dword(&ZOOM_HANN_ROOTS[windowIndex][0]));
  const int32_t ci = int32_t(pgm_read_dword(&ZOOM_HANN_ROOTS[windowIndex][1]));
  const unsigned blocks = nSamples / nFft;
  memset(power, 0, size_t(binCount) * sizeof(*power));
  clipped = 0;
  for (unsigned block = 0; block < blocks; ++block) {
    const unsigned base = block * nFft;
    int32_t sumA = 0, sumB = 0;
    for (unsigned j = 0; j < nFft; ++j) {
      int16_t a, b;
      iqDecode(iqStorage.words[base + j], a, b);
      sumA += a; sumB += b;
      if (a <= -256 || a >= 255 || b <= -256 || b >= 255) ++clipped;
    }
    const int32_t meanA = int32_t(int64_t(sumA) * scale / nFft);
    const int32_t meanB = int32_t(int64_t(sumB) * scale / nFft);
    int32_t wr = one, wi = 0;
    for (unsigned j = 0; j < nFft / 2; ++j) {
      int32_t window = int32_t((int64_t(one) - wr) / 2);
      if (window < 0) window = 0;
      if (window > one) window = one;
      // Symmetric Hann, denominator n-1, and unwindowed mean removal match JS.
      // Fill mirrored samples together: fewer rotations and exactly symmetric
      // coefficients, without allocating a separate window table.
      for (unsigned side = 0; side < 2; ++side) {
        const unsigned k = side ? nFft - 1 - j : j;
        int16_t a, b;
        iqDecode(iqStorage.words[base + k], a, b);
        re[k] = zoomRoundQ30((int64_t(a) * scale - meanA) * window);
        im[k] = zoomRoundQ30((int64_t(meanB) - int64_t(b) * scale) * window);
      }
      const int32_t next = zoomRoundQ30(int64_t(wr) * cr - int64_t(wi) * ci);
      wi = zoomRoundQ30(int64_t(wr) * ci + int64_t(wi) * cr);
      wr = next;
      if ((j & 127u) == 127u) yield();
    }
    zoomFft(re, im, nFft);
    for (unsigned j = 0; j < binCount; ++j) {
      const unsigned bin = (firstBin + j + nFft / 2) % nFft;
      const int64_t r = re[bin], q = im[bin];
      power[j] += float(uint64_t(r * r) + uint64_t(q * q));
    }
    yield();
  }
  // The FFT has been divided by n. Restore its normalization and divide the
  // original signed-10 counts by 512, then by sum(Hann) = (n-1)/2.
  const float normalized = float(nFft) / (512.0f * float(scale) * (float(nFft - 1) * 0.5f));
  const float powerScale = normalized * normalized / float(blocks);
  for (unsigned j = 0; j < binCount; ++j) {
    const float p = power[j] * powerScale;
    const float db = p > 1e-14f ? 10.0f * log10f(p) : -140.0f;
    int32_t encoded = int32_t((db + 140.0f) * 1.6f + 0.5f);
    if (encoded < 0) encoded = 0;
    if (encoded > 255) encoded = 255;
    payload[j] = uint8_t(encoded);
    if ((j & 63u) == 63u) yield();
  }
}

static void zoomPacket(uint16_t nSamples, uint16_t nFft,
                       uint16_t firstBin, uint16_t binCount) {
  if (!iqCapture(nSamples)) {
    if(captureBusySafe)Serial.print("ERR BUSY restored=1 awake=1 intact=1\n");
    else Serial.printf("ERR capture %u\n", unsigned(result.code));
    return;
  }
  // All new work starts here, AFTER the existing capture has fully completed.
  const uint32_t start = micros();
  const size_t bytes = size_t(nFft) * 2 * sizeof(int32_t)
                     + size_t(binCount) * (sizeof(float) + sizeof(uint8_t));
  // Leave room for SDK/serial work and the normal stack. The buffer is released
  // after this one reply, so legacy commands retain their original heap budget.
  if (ESP.getFreeHeap() < bytes + 8192u) {
    Serial.print("ERR ZCAP memory\n");
    return;
  }
  void *storage = malloc(bytes);
  if (!storage) {
    Serial.print("ERR ZCAP memory\n");
    return;
  }
  int32_t *re = static_cast<int32_t *>(storage), *im = re + nFft;
  float *power = reinterpret_cast<float *>(im + nFft);
  uint8_t *payload = reinterpret_cast<uint8_t *>(power + binCount);
  uint16_t clipped = 0;
  zoomSpectrum(nSamples, nFft, firstBin, binCount, re, im, power, payload, clipped);
  uint32_t crc = 0xffffffffu;
  for (unsigned j = 0; j < binCount; ++j) {
    crc = crc32Byte(crc, payload[j]);
    if ((j & 127u) == 127u) yield();
  }
  crc ^= 0xffffffffu;
  const uint32_t processUs = micros() - start;
  const uint32_t captureUs = (result.cycles + CPU_MHZ - 1u) / CPU_MHZ;
  // Below 100 bytes even for the largest decimal uint32_t diagnostics.
  Serial.printf("ZDATA1 %u %u %u %u %u %08x %u %u %u\n",
    unsigned(nSamples), unsigned(nFft), unsigned(firstBin), unsigned(binCount),
    result.sequence, crc, captureUs, processUs, unsigned(clipped));
  for (unsigned offset = 0; offset < binCount;) {
    const size_t count = binCount - offset < 64 ? binCount - offset : 64;
    if (Serial.write(payload + offset, count) != count) {
      ++transmitErrors;
      break; // No diagnostic inserted into a binary reply; host uses SYNC.
    }
    offset += count;
    finishTextChunk(); // Same flush, chunk size and configured pause as CAP20.
  }
  free(storage);
  // No suffix, and no persistent streaming/zoom state.
}

static bool parseUnsigned(const char *text, uint32_t &value) {
  if (!text || !*text) return false;
  uint32_t parsed = 0;
  for (const char *p = text; *p; ++p) {
    if (*p < '0' || *p > '9') return false;
    const uint32_t digit = uint32_t(*p - '0');
    if (parsed > (0xffffffffu - digit) / 10u) return false;
    parsed = parsed * 10u + digit;
  }
  value = parsed;
  return true;
}

// Included after the v6 serializer helpers, with Serial mapped to IQSocket.
namespace SweepCapture {
struct Window {
  uint16_t frequency,words;
  uint32_t sequence,rawCrc,payloadCrc,captureUs,borrowUs;
};
static uint32_t nextId,completed,failed,lastId,lastDurationUs,lastBytes,lastWindows;
static uint32_t lastPmCalls,lastSocketWrites;
static bool guardsOK(const uint8_t* allocation,size_t bytes) {
  for(unsigned i=0;i<16;i++)if(allocation[i]!=uint8_t(0xC3u^(17u*i))||
       allocation[16+bytes+i]!=uint8_t(0x69u^(13u*i)))return false;
  return true;
}
static void capture(uint16_t n,const uint16_t frequencies[3]) {
  lastValid=false;lastWords=0;DirectSession::captureValid=false;
  const size_t bytes=(size_t(n)*20u+7u)/8u,total=bytes*3u;
  if(ESP.getFreeHeap()<total+32u+8192u){Serial.print("ERR SCAN memory\n");return;}
  uint8_t* allocation=static_cast<uint8_t*>(malloc(total+32u));
  if(!allocation){Serial.print("ERR SCAN memory\n");return;}
  for(unsigned i=0;i<16;i++){
    allocation[i]=uint8_t(0xC3u^(17u*i));allocation[16+total+i]=uint8_t(0x69u^(13u*i));
  }
  uint8_t* payload=allocation+16;
  Window windows[3]={};
  const uint32_t started=micros(),pmBefore=PowerSaveControl::stats().calls;
  const uint32_t socketBefore=IQSocket.stats().acceptedBytes;
  lastId=++nextId;lastWindows=0;lastBytes=0;
  const bool asleep=DirectSession::powerSave(true);
  const bool begun=asleep&&WebSdrCapture::beginSession();
  bool captured=begun;
  if(begun)for(unsigned i=0;i<3;i++){
    ++DirectSession::captures;
    if(!WebSdrCapture::captureWindow(frequencies[i],n)){captured=false;break;}
    const auto& r=WebSdrCapture::lastResult();const auto& c=WebSdrCapture::status();
    windows[i].frequency=frequencies[i];windows[i].words=n;
    windows[i].sequence=r.sequence;windows[i].rawCrc=r.hash;
    windows[i].captureUs=(r.cycles+159u)/160u;
    windows[i].borrowUs=(c.borrowCycles+159u)/160u;
    PayloadCursor cursor={};
    if(fillPayload(cursor,n,false,payload+i*bytes,bytes)!=bytes||
       !WebSdrCapture::verifyBufferHash()){captured=false;break;}
    windows[i].payloadCrc=FastCrc32::digest(payload+i*bytes,bytes);
    ++lastWindows;
  }
  // Every outcome returns to the saved AP before resuming network output.
  const bool returned=!begun||WebSdrCapture::endSession();
  const bool awake=DirectSession::powerSave(false);
  lastPmCalls=PowerSaveControl::stats().calls-pmBefore;
  lastDurationUs=micros()-started;
  lastSocketWrites=IQSocket.stats().acceptedBytes-socketBefore;
  DirectSession::captureWindowUs=lastDurationUs;
  result=WebSdrCapture::lastResult();lastWords=WebSdrCapture::count();
  bool intact=guardsOK(allocation,total);
  if(captured)for(unsigned i=0;i<3;i++)
    intact=FastCrc32::digest(payload+i*bytes,bytes)==windows[i].payloadCrc&&intact;
  lastValid=captured&&lastWindows==3&&returned&&awake&&intact&&!lastSocketWrites;
  DirectSession::captureValid=lastValid;DirectSession::captureCode=uint8_t(result.code);
  if(!intact||lastSocketWrites)DirectSession::latchedFault=true;
  if(!lastValid){
    ++failed;++DirectSession::captureFailures;lastWords=0;
    if(asleep&&!WebSdrCapture::status().busy&&!WebSdrCapture::status().rxSessionActive&&WebSdrCapture::status().rxSessionRestored&&result.code==IqStatus::Busy&&returned&&awake&&intact&&!lastSocketWrites&&
       WebSdrCapture::status().rfRestoreVerified&&WebSdrCapture::status().radioRestored&&
       !DirectSession::latchedFault&&WiFi.status()==WL_CONNECTED)
      Serial.print("ERR BUSY restored=1 awake=1 intact=1\n");
    else Serial.printf("ERR SCAN windows=%u returned=%u awake=%u intact=%u code=%u\n",
        unsigned(lastWindows),unsigned(returned),unsigned(awake),unsigned(intact),unsigned(result.code));
    free(allocation);return;
  }
  Serial.printf("SWEEP3 %u %u %u %u %u\n",unsigned(lastId),unsigned(n),
    unsigned(frequencies[0]),unsigned(frequencies[1]),unsigned(frequencies[2]));
  bool sent=true;
  for(unsigned i=0;i<3;i++){
    Serial.printf("WINDOW %u %u %u %08x %u %u\n",i,unsigned(windows[i].frequency),unsigned(n),
      windows[i].payloadCrc,unsigned(windows[i].captureUs),unsigned(windows[i].borrowUs));
    if(Serial.write(payload+i*bytes,bytes)!=bytes){++transmitErrors;sent=false;break;}
  }
  intact=guardsOK(allocation,total);
  for(unsigned i=0;i<3;i++)intact=FastCrc32::digest(payload+i*bytes,bytes)==windows[i].payloadCrc&&intact;
  if(!intact)DirectSession::latchedFault=true;
  if(sent&&intact){++completed;lastBytes=total;}else ++failed;
  free(allocation);
}
static void stats(){
  Serial.printf("SWEEP {\"completed\":%lu,\"failed\":%lu,\"lastId\":%lu,\"lastWindows\":%lu,\"lastBytes\":%lu,\"windowDurationUs\":%lu,\"pmCalls\":%lu,\"offChannelSocketWrites\":%lu}\n",
    completed,failed,lastId,lastWindows,lastBytes,lastDurationUs,lastPmCalls,lastSocketWrites);
}
}

// Diagnostic only: exercises the MAC RX loan without acquiring IQ samples.
namespace GateProbe {
static void run(uint16_t mhz,uint16_t holdUs) {
  lastValid=false;lastWords=0;DirectSession::captureValid=false;
  const bool asleep=DirectSession::powerSave(true);
  const bool begun=asleep&&WebSdrCapture::beginSession();
  const bool probed=begun&&WebSdrCapture::probeMacRxGate(mhz,holdUs);
  const bool returned=!begun||WebSdrCapture::endSession();
  const bool awake=DirectSession::powerSave(false);
  Serial.printf("GATEPROBE {\"frequencyMHz\":%u,\"holdUs\":%u,\"ok\":%u,\"returned\":%u,\"awake\":%u}\n",
    unsigned(mhz),unsigned(holdUs),unsigned(probed),unsigned(returned),unsigned(awake));
}
}

static void handleCommand(char *line) {
  // SYNC echo is byte-exact for one printable token, followed by LF only.
  if (!strncmp(line, "SYNC ", 5)) {
    const char *token = line + 5;
    if (!*token || strchr(token, ' ') || strchr(token, '\t')) {
      Serial.print("ERR SYNC token\n");
      return;
    }
    Serial.write(reinterpret_cast<const uint8_t *>(line), strlen(line));
    Serial.write(uint8_t('\n'));
    return;
  }

  char *tokens[5];
  unsigned count = 0;
  char *p = line;
  while (*p) {
    while (*p == ' ' || *p == '\t') ++p;
    if (!*p) break;
    if (count == 5) {
      Serial.print("ERR too many arguments\n");
      return;
    }
    tokens[count++] = p;
    while (*p && *p != ' ' && *p != '\t') ++p;
    if (*p) *p++ = 0;
  }
  if (!count) return;

  uint32_t value = 0, rate = 0;
  if (!strcmp(tokens[0], "INFO") && count == 1) {
    // Identity contract: spaces around "burst", and the actual sample limit.
    // INFO identifies the protocol even after init failure; STAT? exposes it.
    Serial.print("ESP8266SDR 6 burst 2048\n");
  } else if (!strcmp(tokens[0], "CAPS") && count == 1) {
    Serial.print(ENABLE_FINE_TUNE ? "CAPS RXLIMITS GAIN TUNEEXT ZOOMFFT WEBSOCKET NETINFO PERF SWEEP3\n"
                                 : "CAPS RXLIMITS GAIN ZOOMFFT WEBSOCKET NETINFO PERF SWEEP3\n");
  } else if (!strcmp(tokens[0], "RANGE?") && count == 1 && ENABLE_FINE_TUNE) {
    Serial.printf("RANGE %u %u %u\n",unsigned(WebSdrCapture::MinimumMHz),unsigned(WebSdrCapture::MaximumMHz),unsigned(WebSdrCapture::tuneStepMHz()));
  } else if (!strcmp(tokens[0], "LIMITS?") && count == 1) {
    Serial.print("LIMITS {\"gain\":[0,29,1],\"bandwidth\":null,"
                 "\"rates\":[40000000],\"bits\":[10]}\n");
  } else if (!strcmp(tokens[0], "TRANSPORT?") && count == 1) {
    Serial.print("TRANSPORT WEBSOCKET 81\n");
  } else if (!strcmp(tokens[0], "GAIN?") && count == 1) {
    Serial.printf("GAIN MANUAL %u 0 29\n", unsigned(manualGain));
  } else if (!strcmp(tokens[0], "STAT?") && count == 1) {
    printStatus();
  } else if (!strcmp(tokens[0], "RAW?") && count == 1) {
    rawPacket();
  } else if (!strcmp(tokens[0], "GATEPROBE")) {
    uint32_t mhz=0,hold=0;
    if(count!=3||!parseUnsigned(tokens[1],mhz)||!parseUnsigned(tokens[2],hold)||
       mhz>65535u||!WebSdrCapture::supportsFrequency(uint16_t(mhz))||hold>250u)
      Serial.print("ERR GATEPROBE frequency and hold0..250us\n");
    else GateProbe::run(uint16_t(mhz),uint16_t(hold));
  } else if (!strcmp(tokens[0], "SCAN")) {
    uint32_t n=0,f0=0,f1=0,f2=0;
    if(count!=5||!parseUnsigned(tokens[1],n)||!parseUnsigned(tokens[2],f0)||
       !parseUnsigned(tokens[3],f1)||!parseUnsigned(tokens[4],f2)||n<2||n>2048||
       f0>=f1||f1>=f2||f0>65535u||f1>65535u||f2>65535u||
       !WebSdrCapture::supportsFrequency(uint16_t(f0))||!WebSdrCapture::supportsFrequency(uint16_t(f1))||
       !WebSdrCapture::supportsFrequency(uint16_t(f2)))Serial.print("ERR SCAN samples2..2048 and three ordered supported frequencies\n");
    else {const uint16_t frequencies[3]={uint16_t(f0),uint16_t(f1),uint16_t(f2)};SweepCapture::capture(uint16_t(n),frequencies);}
  } else if (!strcmp(tokens[0], "CAP20") && count == 3
             && parseUnsigned(tokens[1], value) && parseUnsigned(tokens[2], rate)) {
    if (value < 2 || value > MAX_WORDS || rate != 1) {
      invalidate(IqStatus::BadSize);
      result.requested = value;
      Serial.print("ERR CAP20 requires 2..2048 samples and rate 1\n");
    } else {
      capturePacket(uint16_t(value));
    }
  } else if (!strcmp(tokens[0], "ZCAP")) {
    uint32_t n = 0, fft = 0, first = 0, bins = 0;
    if (count != 5 || !parseUnsigned(tokens[1], n)
        || !parseUnsigned(tokens[2], fft) || !parseUnsigned(tokens[3], first)
        || !parseUnsigned(tokens[4], bins)
        || (fft != 512 && fft != 1024 && fft != 2048)
        || n > MAX_WORDS || n < fft || n % fft != 0
        || first >= fft || bins == 0 || bins > fft - first) {
      Serial.print("ERR ZCAP requires samples/FFT 512..2048 and valid bin window\n");
    } else {
      zoomPacket(uint16_t(n), uint16_t(fft), uint16_t(first), uint16_t(bins));
    }
  } else if (!strcmp(tokens[0], "FREQ") && count == 2
             && parseUnsigned(tokens[1], value)) {
    if (value < 2412 || value > 2462
        || ((value - WebSdrCapture::MinimumMHz) % WebSdrCapture::tuneStepMHz())) {
      Serial.print(ENABLE_FINE_TUNE ? "ERR FREQ requires integer 2412..2462 MHz\n"
                                   : "ERR FREQ requires 2412..2462 MHz in steps of 5\n");
    } else {
      if (!iqTuneFrequency(uint16_t(value)))
        Serial.printf("ERR frequency %u\n", unsigned(result.code));
      else
        Serial.printf("OK FREQ %u\n", value);
    }
  } else if (!strcmp(tokens[0], "GAIN") && count == 3
             && !strcmp(tokens[1], "MANUAL") && parseUnsigned(tokens[2], value)) {
    if (value > 29) Serial.print("ERR GAIN requires MANUAL 0..29\n");
    else if (!iqSetGain(uint8_t(value)))
      Serial.printf("ERR gain %u\n", unsigned(result.code));
    else
      Serial.printf("OK GAIN MANUAL %u\n", value);
  } else {
    Serial.print("ERR command\n");
  }
}

#undef Serial
#include <ESP8266WebServer.h>

// ===== BEGIN integrated tx_config.h =====
#ifndef ESPBOOM8266TX_V02_TX_CONFIG_H
#define ESPBOOM8266TX_V02_TX_CONFIG_H

#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

namespace TxConfig {

struct Value {
  uint16_t frequencyMHz = 2412;
  uint8_t ask = 63;
  uint8_t apwr = 63;
  uint8_t dutyPercent = 10;
  uint32_t periodUs = 10000;
  uint16_t networkIntervalMs = 2000;
};

namespace Detail {
inline bool digit(char c) { return c >= '0' && c <= '9'; }
inline void whitespace(const char *&p) {
  while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') ++p;
}
inline int hex(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  if (c >= 'A' && c <= 'F') return c - 'A' + 10;
  return -1;
}
// Known keys are ASCII. Decode escaped ASCII so equivalent spellings cannot
// bypass duplicate detection. Non-ASCII or control characters cannot name a key.
inline bool key(const char *&p, char (&out)[24]) {
  if (*p++ != '"') return false;
  size_t size = 0;
  while (*p && *p != '"') {
    unsigned char c = static_cast<unsigned char>(*p++);
    if (c == '\\') {
      const char escaped = *p++;
      if (escaped == 'u') {
        unsigned code = 0;
        for (unsigned i = 0; i < 4; ++i) {
          if (!*p) return false;
          const int value = hex(*p++);
          if (value < 0) return false;
          code = (code << 4) | static_cast<unsigned>(value);
        }
        if (code < 0x20 || code > 0x7f) return false;
        c = static_cast<unsigned char>(code);
      } else if (escaped == '"' || escaped == '\\' || escaped == '/') {
        c = static_cast<unsigned char>(escaped);
      } else {
        return false;
      }
    }
    if (c < 0x20 || c > 0x7f || size + 1 >= sizeof(out)) return false;
    out[size++] = static_cast<char>(c);
  }
  if (*p != '"') return false;
  ++p;
  out[size] = '\0';
  return true;
}
inline bool number(const char *&p, double &out) {
  const char *begin = p;
  if (*p == '-') ++p;
  if (*p == '0') {
    ++p;
    if (digit(*p)) return false;
  } else {
    if (*p < '1' || *p > '9') return false;
    do { ++p; } while (digit(*p));
  }
  if (*p == '.') {
    ++p;
    if (!digit(*p)) return false;
    do { ++p; } while (digit(*p));
  }
  if (*p == 'e' || *p == 'E') {
    ++p;
    if (*p == '+' || *p == '-') ++p;
    if (!digit(*p)) return false;
    do { ++p; } while (digit(*p));
  }
  const size_t length = static_cast<size_t>(p - begin);
  if (length == 0 || length >= 64) return false;
  char token[64];
  memcpy(token, begin, length);
  token[length] = '\0';
  errno = 0;
  char *end = nullptr;
  const double value = strtod(token, &end);
  if (errno == ERANGE || end != token + length || !isfinite(value)) return false;
  out = value;
  return true;
}
inline bool integer(double value, unsigned min, unsigned max) {
  return value >= min && value <= max && floor(value) == value;
}
} // namespace Detail

// Strict flat JSON: every required key exactly once; no additional properties,
// strings, arrays, nested objects, non-JSON numbers, or trailing input. The caller's
// value changes only after the entire request has passed validation.
inline bool parse(const char *json, Value &out) {
  if (!json) return false;
  const char *p = json;
  Detail::whitespace(p);
  if (*p++ != '{') return false;
  Value candidate;
  unsigned seen = 0;
  for (;;) {
    Detail::whitespace(p);
    char name[24];
    if (!Detail::key(p, name)) return false;
    unsigned field;
    if (!strcmp(name, "frequencyMHz")) field = 0;
    else if (!strcmp(name, "ask")) field = 1;
    else if (!strcmp(name, "apwr")) field = 2;
    else if (!strcmp(name, "dutyPercent")) field = 3;
    else if (!strcmp(name, "periodMs")) field = 4;
    else if (!strcmp(name, "networkIntervalMs")) field = 5;
    else return false;
    const unsigned bit = 1u << field;
    if (seen & bit) return false;
    seen |= bit;
    Detail::whitespace(p);
    if (*p++ != ':') return false;
    Detail::whitespace(p);
    double value;
    if (!Detail::number(p, value)) return false;
    switch (field) {
      case 0:
        if (!Detail::integer(value, 2412, 2462)) return false;
        candidate.frequencyMHz = static_cast<uint16_t>(value);
        break;
      case 1:
        if (!Detail::integer(value, 0, 63)) return false;
        candidate.ask = static_cast<uint8_t>(value);
        break;
      case 2:
        if (!Detail::integer(value, 0, 127)) return false;
        candidate.apwr = static_cast<uint8_t>(value);
        break;
      case 3:
        if (!Detail::integer(value, 0, 90)) return false;
        candidate.dutyPercent = static_cast<uint8_t>(value);
        break;
      case 4:
        if (!Detail::integer(value, 2, 100)) return false;
        candidate.periodUs = static_cast<uint32_t>(value) * 1000u;
        break;
      case 5:
        if (value != 2000 && value != 3000) return false;
        candidate.networkIntervalMs = static_cast<uint16_t>(value);
        break;
    }
    Detail::whitespace(p);
    if (*p == '}') {
      ++p;
      Detail::whitespace(p);
      if (*p != '\0' || seen != 63u) return false;
      out = candidate;
      return true;
    }
    if (*p++ != ',') return false;
  }
}

// Pulse durations during the custom-TX block. Network pauses are separate.
// Round ON down so quantization can never increase the requested RF duty.
inline uint32_t onUs(const Value &value) {
  return static_cast<uint32_t>((static_cast<uint64_t>(value.periodUs) * value.dutyPercent) / 100u);
}
inline uint32_t offUs(const Value &value) { return value.periodUs - onUs(value); }

// Wrap-safe comparison: only use deadlines less than 2^31 ticks away.
inline bool due(uint32_t now, uint32_t deadline) {
  return static_cast<int32_t>(now - deadline) >= 0;
}

} // namespace TxConfig
#endif

// ===== END integrated tx_config.h =====
// ===== BEGIN integrated heartbeat_lease.h =====
#ifndef ESPBOOM8266TX_V02_HEARTBEAT_LEASE_H
#define ESPBOOM8266TX_V02_HEARTBEAT_LEASE_H
#include <stdint.h>
#include <stddef.h>
#include <string.h>

namespace Heartbeat {
// This class guards APPLICATION confirmation only. The RF block needs its own
// independent hardware/foreground deadline; Active is never permission to run
// an RF block forever. All time arguments below use one caller-selected tick
// unit (normally milliseconds), and outstanding deadlines must be < 2^31 away.
class Lease {
 public:
  enum class State : uint8_t { Stopped, Active, Awaiting };
  static constexpr uint32_t MaxTimeout = 0x7fffffffu;

  // Explicit user Start is the only operation that can leave Stopped. A random
  // nonzero session number separates restarts; it is not an authentication key.
  bool start(const char *clientId, uint32_t sessionId) {
    if (!validClientId(clientId) || !sessionId) return false;
    memcpy(clientId_,clientId,sizeof(clientId_));
    sessionId_=sessionId;cycle_=nonce_=deadline_=0;
    sequenceIssued_=false;state_=State::Active;
    return true;
  }

  // Issue once after returning to Wi-Fi. Network retransmissions reuse the SAME
  // challenge and deadline. Re-issuing while Awaiting cannot extend the lease.
  bool issue(uint32_t cycle, uint32_t nonce, uint32_t now, uint32_t timeout=500) {
    expire(now);
    if (state_!=State::Active || !timeout || timeout>MaxTimeout) return false;
    if (sequenceIssued_ && static_cast<int32_t>(cycle-cycle_)<=0) return false;
    cycle_=cycle;nonce_=nonce;deadline_=now+timeout;
    sequenceIssued_=true;state_=State::Awaiting;
    return true;
  }

  // A valid confirmation is consumed exactly once. Wrong, stale, unsolicited,
  // expired, negative, or replayed confirmations never grant a TX block.
  bool confirm(const char *clientId, uint32_t sessionId, uint32_t cycle,
               uint32_t nonce, bool continueTx, uint32_t now) {
    expire(now);
    if (state_!=State::Awaiting || !validClientId(clientId) ||
        strcmp(clientId_,clientId) || sessionId!=sessionId_ ||
        cycle!=cycle_ || nonce!=nonce_) return false;
    if (!continueTx) { stop();return false; }
    state_=State::Active;deadline_=0;
    return true;
  }

  // Timeout is fail-closed and cannot be reversed by a delayed confirmation.
  bool expire(uint32_t now) {
    if (state_==State::Awaiting && static_cast<int32_t>(now-deadline_)>=0) {
      stop();return true;
    }
    return false;
  }
  void stop() {
    state_=State::Stopped;clientId_[0]='\0';
    sessionId_=cycle_=nonce_=deadline_=0;sequenceIssued_=false;
  }

  State state() const { return state_; }
  bool enabled() const { return state_!=State::Stopped; }
  bool active() const { return state_==State::Active; }
  bool awaiting() const { return state_==State::Awaiting; }
  const char *clientId() const { return clientId_; }
  uint32_t sessionId() const { return sessionId_; }
  uint32_t cycle() const { return cycle_; }
  uint32_t nonce() const { return nonce_; }
  uint32_t deadline() const { return deadline_; }

  static bool validClientId(const char *s) {
    if (!s) return false;
    for (size_t i=0;i<32;++i) {
      const char c=s[i];
      if (!((c>='0'&&c<='9')||(c>='a'&&c<='f'))) return false;
    }
    return s[32]=='\0';
  }
 private:
  State state_=State::Stopped;
  char clientId_[33]={};
  uint32_t sessionId_=0,cycle_=0,nonce_=0,deadline_=0;
  bool sequenceIssued_=false;
};
} // namespace Heartbeat
#endif

// ===== END integrated heartbeat_lease.h =====
// ===== BEGIN integrated control_messages.h =====
#ifndef ESPBOOM8266TX_V02_CONTROL_MESSAGES_H
#define ESPBOOM8266TX_V02_CONTROL_MESSAGES_H
// tx_config.h already integrated above.
// heartbeat_lease.h already integrated above.

namespace ControlMessages {
struct Request {
  uint32_t requestId=0;
  char method[5]={},path[24]={},body[257]={};
};
struct Confirm {
  char clientId[33]={};
  uint32_t sessionId=0,cycle=0,nonce=0;
  bool continueTx=false;
};
namespace Detail {
enum class Kind { Start,Hello,Confirm,Stop };
struct Fields {
  char type[8]={},clientId[33]={};
  uint32_t sessionId=0,cycle=0,nonce=0;
  bool continueTx=false;
};
template<size_t N> inline bool string(const char *&p,char (&out)[N],bool allowEscapedControls=false) {
  if (*p!='"') return false;
  ++p;size_t n=0;
  while (*p && *p!='"') {
    unsigned char c=static_cast<unsigned char>(*p++);
    bool escapedControl=false;
    if(c=='\\') {
      const char e=*p++;
      if(e=='u') {
        unsigned value=0;
        for(unsigned i=0;i<4;++i) {
          if(!*p)return false;
          const int h=TxConfig::Detail::hex(*p++);
          if(h<0)return false;
          value=(value<<4)|static_cast<unsigned>(h);
        }
        // Current control/configuration schema is ASCII. NUL cannot be carried
        // in a C-string body, and non-ASCII code points are intentionally refused.
        if(!value||value>0x7e)return false;
        c=static_cast<unsigned char>(value);escapedControl=c<0x20;
      }else if(e=='"'||e=='\\'||e=='/')c=static_cast<unsigned char>(e);
      else if(allowEscapedControls&&(e=='b'||e=='f'||e=='n'||e=='r'||e=='t')){
        c=e=='b'?'\b':e=='f'?'\f':e=='n'?'\n':e=='r'?'\r':'\t';escapedControl=true;
      }else return false;
    }
    if(!c||c>0x7e||(c<0x20&&!(allowEscapedControls&&escapedControl))||n+1>=N)return false;
    out[n++]=static_cast<char>(c);
  }
  if(*p!='"')return false;
  ++p;out[n]='\0';return true;
}
inline bool boolean(const char *&p,bool &out) {
  if(!strncmp(p,"true",4)){p+=4;out=true;return true;}
  if(!strncmp(p,"false",5)){p+=5;out=false;return true;}
  return false;
}
inline bool uint32(const char *&p,uint32_t &out) {
  double value;
  if(!TxConfig::Detail::number(p,value)||value<0||value>4294967295.0||floor(value)!=value)return false;
  out=static_cast<uint32_t>(value);return true;
}
inline bool parse(const char *json,Kind kind,Fields &out) {
  if(!json)return false;
  const char *p=json;TxConfig::Detail::whitespace(p);
  if(*p++!='{')return false;
  const unsigned required=kind==Kind::Start?2u:kind==Kind::Hello?3u:kind==Kind::Confirm?63u:1u;
  unsigned seen=0;Fields candidate;
  for(;;){
    TxConfig::Detail::whitespace(p);char key[24];
    if(!TxConfig::Detail::key(p,key))return false;
    unsigned bit;
    if(!strcmp(key,"type"))bit=1;
    else if(!strcmp(key,"clientId"))bit=2;
    else if(!strcmp(key,"sessionId"))bit=4;
    else if(!strcmp(key,"cycle"))bit=8;
    else if(!strcmp(key,"nonce"))bit=16;
    else if(!strcmp(key,"continue"))bit=32;
    else return false;
    if(!(required&bit)||(seen&bit))return false;
    seen|=bit;TxConfig::Detail::whitespace(p);
    if(*p++!=':')return false;
    TxConfig::Detail::whitespace(p);
    if(bit==1){if(!string(p,candidate.type))return false;}
    else if(bit==2){if(!string(p,candidate.clientId)||!Heartbeat::Lease::validClientId(candidate.clientId))return false;}
    else if(bit==4){if(!uint32(p,candidate.sessionId))return false;}
    else if(bit==8){if(!uint32(p,candidate.cycle))return false;}
    else if(bit==16){if(!uint32(p,candidate.nonce))return false;}
    else if(!boolean(p,candidate.continueTx))return false;
    TxConfig::Detail::whitespace(p);
    if(*p=='}'){
      ++p;TxConfig::Detail::whitespace(p);
      if(*p||seen!=required)return false;
      const char *expected=kind==Kind::Hello?"hello":kind==Kind::Confirm?"confirm":kind==Kind::Stop?"stop":"";
      if(strcmp(candidate.type,expected))return false;
      out=candidate;return true;
    }
    if(*p++!=',')return false;
  }
}
} // namespace Detail

// Outputs remain untouched on failure. Client IDs are exactly32 lowercase hex.
inline bool parseStart(const char *json,char (&clientId)[33]) {
  Detail::Fields value;
  if(!Detail::parse(json,Detail::Kind::Start,value))return false;
  memcpy(clientId,value.clientId,33);return true;
}
inline bool parseHello(const char *json,char (&clientId)[33]) {
  Detail::Fields value;
  if(!Detail::parse(json,Detail::Kind::Hello,value))return false;
  memcpy(clientId,value.clientId,33);return true;
}
inline bool parseConfirm(const char *json,Confirm &out) {
  Detail::Fields value;
  if(!Detail::parse(json,Detail::Kind::Confirm,value))return false;
  Confirm candidate;
  memcpy(candidate.clientId,value.clientId,33);
  candidate.sessionId=value.sessionId;candidate.cycle=value.cycle;
  candidate.nonce=value.nonce;candidate.continueTx=value.continueTx;
  out=candidate;return true;
}
inline bool parseStop(const char *json) {
  Detail::Fields value;return Detail::parse(json,Detail::Kind::Stop,value);
}

// Bounded RPC over the already established WebSocket. Its inner JSON body is
// decoded here, then validated by the existing endpoint-specific parser.
// Exactly the four supported method/path pairs are accepted; no query strings.
inline bool parseRequest(const char *json,Request &out) {
  if(!json)return false;
  const char *p=json;TxConfig::Detail::whitespace(p);
  if(*p++!='{')return false;
  unsigned seen=0;Request candidate;char type[8]={};
  for(;;){
    TxConfig::Detail::whitespace(p);char key[24];
    if(!TxConfig::Detail::key(p,key))return false;
    unsigned bit;
    if(!strcmp(key,"type"))bit=1;
    else if(!strcmp(key,"requestId"))bit=2;
    else if(!strcmp(key,"method"))bit=4;
    else if(!strcmp(key,"path"))bit=8;
    else if(!strcmp(key,"body"))bit=16;
    else return false;
    if(seen&bit)return false;
    seen|=bit;TxConfig::Detail::whitespace(p);
    if(*p++!=':')return false;
    TxConfig::Detail::whitespace(p);
    if(bit==1){if(!Detail::string(p,type))return false;}
    else if(bit==2){if(!Detail::uint32(p,candidate.requestId)||!candidate.requestId)return false;}
    else if(bit==4){if(!Detail::string(p,candidate.method))return false;}
    else if(bit==8){if(!Detail::string(p,candidate.path))return false;}
    else if(!Detail::string(p,candidate.body,true))return false;
    TxConfig::Detail::whitespace(p);
    if(*p=='}'){
      ++p;TxConfig::Detail::whitespace(p);
      if(*p||seen!=31u||strcmp(type,"request"))return false;
      const bool get=!strcmp(candidate.method,"GET");
      const bool post=!strcmp(candidate.method,"POST");
      const bool status=!strcmp(candidate.path,"/api/status");
      const bool config=!strcmp(candidate.path,"/api/config");
      const bool start=!strcmp(candidate.path,"/api/start");
      const bool stop=!strcmp(candidate.path,"/api/stop");
      if(!((get&&status)||(post&&(config||start||stop))))return false;
      if((get||stop)&&candidate.body[0])return false;
      out=candidate;return true;
    }
    if(*p++!=',')return false;
  }
}

} // namespace ControlMessages
#endif

// ===== END integrated control_messages.h =====
// ===== BEGIN integrated long_tx.h =====
#include <Arduino.h>
// ===== BEGIN integrated tx_phy_loan.h =====
#include <Arduino.h>

// Research integration component, not a complete radio arbiter.
// Caller MUST already own the PHY, stop/gate MAC RX, establish hardware RX/TX
// idle, and preserve/mask CPU interrupts. No Wi-Fi SDK callbacks may execute
// between save() and restore(). Keep the FIRST tests within a bounded 0.5-2 ms
// RF burst. This file does not select a PLL channel or alter Wi-Fi association.
//
// Source: kaboom748 PHY v6 documents and TX_REFERENCE_v1.ino; clock side effects
// independently decoded from ROM 0x4000650c and scale from 0x4000678c.
namespace TxPhyLoan {
static constexpr uint32_t PbusCmd = 0x60000594u, PbusStat = 0x600005A0u;
static constexpr uint32_t Tone1 = 0x600005B8u, Tone2 = 0x600005BCu, Tone3 = 0x600005C4u;
static constexpr uint32_t Gate = 1u << 18, ToneMask = 0x3FFu;

struct Saved {
  uint32_t command, tone[3];
  uint16_t p21, p71, p11, p61;
  uint8_t analog9, clock77_28, clock7c_21;
  bool active = false;
};

static inline uint32_t IRAM_ATTR rd(uint32_t a) { return *reinterpret_cast<volatile uint32_t *>(a); }
static inline void IRAM_ATTR wr(uint32_t a, uint32_t v) {
  *reinterpret_cast<volatile uint32_t *>(a) = v;
  __asm__ volatile("memw" ::: "memory");
}
static inline uint32_t IRAM_ATTR cycles() {
  uint32_t n; __asm__ volatile("rsr %0, ccount" : "=a"(n)); return n;
}
static inline uint8_t IRAM_ATTR i2cRead(uint32_t block, uint32_t host, uint32_t reg) {
  using Fn = uint32_t (*)(uint32_t, uint32_t, uint32_t);
  return uint8_t(reinterpret_cast<Fn>(0x40007268u)(block, host, reg));
}
static inline void IRAM_ATTR i2cWrite(uint32_t block, uint32_t host, uint32_t reg, uint8_t value) {
  using Fn = void (*)(uint32_t, uint32_t, uint32_t, uint32_t);
  reinterpret_cast<Fn>(0x400072D8u)(block, host, reg, value);
}
static inline uint16_t IRAM_ATTR pbusRead(uint32_t selector, uint32_t bank) {
  using Fn = uint32_t (*)(uint32_t, uint32_t);
  return uint16_t(reinterpret_cast<Fn>(0x400074D8u)(selector, bank) & 0x1FFu);
}
static bool IRAM_ATTR pbusWrite(uint32_t selector, uint16_t value) {
  const uint32_t start = cycles();
  if ((rd(PbusStat) & 0x80000000u) || (rd(PbusCmd) & 2u)) return false;
  wr(PbusCmd, (rd(PbusCmd) & 0xFFFF0001u) | (1u << 14) |
      (uint32_t(value & 0x1FFu) << 5) | ((selector & 7u) << 2) | 2u);
  while (rd(PbusStat) & 0x80000000u) {
    if (uint32_t(cycles() - start) >= 160u * 250u) {
      wr(PbusCmd, rd(PbusCmd) & ~2u); return false;
    }
  }
  wr(PbusCmd, rd(PbusCmd) & ~2u);
  return true;
}

// No RF emission. Reject an already active test tone rather than overwriting it.
static bool IRAM_ATTR save(Saved &s) {
  if (s.active || (rd(PbusStat) & 0x80000000u) || (rd(PbusCmd) & 2u)) return false;
  s.command = rd(PbusCmd);
  s.tone[0] = rd(Tone1); s.tone[1] = rd(Tone2); s.tone[2] = rd(Tone3);
  if ((s.tone[0] | s.tone[1] | s.tone[2]) & Gate) return false;
  s.p21 = pbusRead(2,1); s.p71 = pbusRead(7,1);
  s.p11 = pbusRead(1,1); s.p61 = pbusRead(6,1);
  s.analog9 = i2cRead(0x77,0,9);
  s.clock77_28 = i2cRead(0x77,0,28);
  s.clock7c_21 = i2cRead(0x7C,1,21);
  s.active = true;
  return true;
}

// Prepare a silent TX. gate(false) remains in effect until the caller starts
// its measured RF frame. APWR is a RAW selector, not dBm. ASK=0 is strongest in
// the documented digital scale convention; gate(false) is the stop command.
static bool IRAM_ATTR prepare(Saved &s, uint16_t tone, uint8_t ask, uint8_t apwr) {
  if (!s.active || tone > 1023u || ask > 63u) return false;
  wr(PbusCmd, rd(PbusCmd) | 1u);
  // Same four-write RF TX path used by TX_REFERENCE_v1 and the R7 modem.
  if (!pbusWrite(2,1) || !pbusWrite(7,95) || !pbusWrite(1,127) || !pbusWrite(6,127)) return false;
  using ScaleFn = uint8_t (*)(uint8_t);
  using ClockFn = void (*)(int);
  // Return value intentionally unused: ASK below is an independent explicit
  // digital scale, rather than the digital component returned for APWR.
  reinterpret_cast<ScaleFn>(0x4000678Cu)(apwr);
  reinterpret_cast<ClockFn>(0x4000650Cu)(1);
  // Canonical normal-mode slot, with the gate initially OFF. Clear stale modes.
  wr(Tone1, (s.tone[0] & 0xF0000000u) | (uint32_t(uint8_t(0u - ask)) << 10) | tone);
  wr(Tone2, s.tone[1] & ~Gate); wr(Tone3, s.tone[2] & ~Gate);
  return pbusRead(2,1) == 1 && pbusRead(7,1) == 95 &&
      pbusRead(1,1) == 127 && pbusRead(6,1) == 127 &&
      (i2cRead(0x77,0,28) & 0x40u) && (i2cRead(0x7C,1,21) & 1u) && !(rd(Tone1) & Gate);
}
static inline void IRAM_ATTR gate(bool enabled) {
  wr(Tone1, enabled ? rd(Tone1) | Gate : rd(Tone1) & ~Gate);
}
static inline void IRAM_ATTR setTone(uint16_t tone) {
  wr(Tone1, (rd(Tone1) & ~ToneMask) | (tone & ToneMask));
}

// Call on EVERY exit after save(), including a partial prepare() failure.
// Restores only the two clock bits owned by set_txclk_en, preserving other
// CURRENT I2C fields. Parent restores its PLL/capture/MAC state afterwards.
static bool IRAM_ATTR restore(Saved &s) {
  if (!s.active) return true;
  bool ok = true;
  wr(Tone1, rd(Tone1) & ~Gate); wr(Tone2, rd(Tone2) & ~Gate); wr(Tone3, rd(Tone3) & ~Gate);
  wr(PbusCmd, rd(PbusCmd) | 1u);
  // Restore TX power paths before restoring the input path last.
  if (!pbusWrite(6,s.p61)) ok = false;
  if (!pbusWrite(1,s.p11)) ok = false;
  if (!pbusWrite(7,s.p71)) ok = false;
  if (!pbusWrite(2,s.p21)) ok = false;
  i2cWrite(0x77,0,9,s.analog9);
  i2cWrite(0x77,0,28,uint8_t((i2cRead(0x77,0,28) & ~0x40u) | (s.clock77_28 & 0x40u)));
  i2cWrite(0x7C,1,21,uint8_t((i2cRead(0x7C,1,21) & ~1u) | (s.clock7c_21 & 1u)));
  wr(Tone1,s.tone[0]); wr(Tone2,s.tone[1]); wr(Tone3,s.tone[2]);
  // PBUS readback belongs before AUTO is released: automatic values may vary.
  if (pbusRead(2,1) != s.p21 || pbusRead(7,1) != s.p71 ||
      pbusRead(1,1) != s.p11 || pbusRead(6,1) != s.p61) ok = false;
  if (i2cRead(0x77,0,9) != s.analog9 ||
      ((i2cRead(0x77,0,28) ^ s.clock77_28) & 0x40u) ||
      ((i2cRead(0x7C,1,21) ^ s.clock7c_21) & 1u)) ok = false;
  if (rd(Tone1) != s.tone[0] || rd(Tone2) != s.tone[1] || rd(Tone3) != s.tone[2]) ok = false;
  wr(PbusCmd,s.command & ~2u);
  if (rd(PbusCmd) != (s.command & ~2u)) ok = false;
  s.active = false;
  return ok;
}
} // namespace TxPhyLoan

// ===== END integrated tx_phy_loan.h =====
// Single CONT call, no yield/SDK/network while foreign RF is borrowed.
// CPU IRQs remain enabled for FRC1; only WDEV events are deferred until HOME.
namespace LongTx {
static constexpr uint32_t IntEna=0x3FF20C18u;
struct Stats {uint32_t requestedUs=0,elapsedUs=0,onUs=0,edges=0,abortCode=0,maxIrqUs=0,deadlineLateUs=0;bool prepared=false,restored=true,interruptRestored=true;};
static volatile uint32_t started=0,durationCycles=0,onCycles=0,offCycles=0,lastOn=0,totalOn=0,edges=0,abortCode=0,finished=0;
static volatile bool gateOn=false,done=true;
static uint32_t savedInterrupts=0;
static bool interruptLoan=false;
static inline uint32_t IRAM_ATTR cyc(){return TxPhyLoan::cycles();}
static void IRAM_ATTR endGate(uint32_t now){
 if(gateOn){TxPhyLoan::gate(false);totalOn+=uint32_t(now-lastOn);gateOn=false;}
 finished=now;done=true;timer1_disable();
}
static void IRAM_ATTR armNext(uint32_t delayCycles,uint32_t now){
 const uint32_t elapsed=now-started;
 if(elapsed>=durationCycles){endGate(now);return;}
 const uint32_t remaining=durationCycles-elapsed;
 if(delayCycles>remaining)delayCycles=remaining;
 uint32_t us=delayCycles/160u;if(us<2u)us=2u;
 timer1_write(us*5u); // 80 MHz / 16 = 5 MHz.
}
static void IRAM_ATTR tick(){
 const uint32_t now=cyc();
 if(done){TxPhyLoan::gate(false);timer1_disable();return;}
 if(uint32_t(now-started)>=durationCycles){endGate(now);return;}
 ++edges;
 if(gateOn){TxPhyLoan::gate(false);totalOn+=uint32_t(now-lastOn);gateOn=false;armNext(offCycles,now);}
 else{TxPhyLoan::gate(true);gateOn=true;lastOn=now;armNext(onCycles,now);}
}
static bool restoreInterrupts(){
 if(!interruptLoan)return true;
 uint32_t ps;__asm__ volatile("rsil %0,15\n\trsync":"=a"(ps)::"memory");
 TxPhyLoan::wr(IntEna,savedInterrupts);
 const bool ok=TxPhyLoan::rd(IntEna)==savedInterrupts;interruptLoan=false;
 __asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");return ok;
}
static bool run(uint32_t durationUs,uint32_t periodUs,uint8_t duty,uint8_t ask,uint8_t apwr,Stats &out){
 out={};out.requestedUs=durationUs;
 if(interruptLoan||durationUs<1000u||durationUs>3000000u||periodUs<2000u||periodUs>100000u||!duty||duty>90u)return false;
 uint32_t ps;
 if(!WebSdrCapture::awaitMacIdle(true,&ps)){out.abortCode=1;return false;}
 const uint32_t entry=cyc();
 bool idle=!(WebSdrCapture::rd(WebSdrCapture::MacRxControl)&WebSdrCapture::MacRxEnable);
 for(uint8_t q=0;q<8;++q)if(TxPhyLoan::rd(0x3FF20DC4u-24u*q)&0xC0000000u)idle=false;
 if(!idle){__asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");out.abortCode=2;return false;}
 savedInterrupts=TxPhyLoan::rd(IntEna);interruptLoan=true;TxPhyLoan::wr(IntEna,0);
 const uint32_t oldStop=WebSdrCapture::rd(WebSdrCapture::RxCtrl)&WebSdrCapture::RxStop;
 WebSdrCapture::wr(WebSdrCapture::RxCtrl,WebSdrCapture::rd(WebSdrCapture::RxCtrl)|WebSdrCapture::RxStop);
 TxPhyLoan::Saved saved;
 bool ok=TxPhyLoan::rd(IntEna)==0&&TxPhyLoan::save(saved);
 if(ok)ok=TxPhyLoan::prepare(saved,0,ask,apwr);
 if(ok){
  timer1_disable();timer1_detachInterrupt();timer1_isr_init();timer1_attachInterrupt(tick);timer1_enable(TIM_DIV16,TIM_EDGE,TIM_SINGLE);
  durationCycles=durationUs*160u;onCycles=(periodUs*duty/100u)*160u;offCycles=periodUs*160u-onCycles;
  totalOn=edges=abortCode=0;done=false;gateOn=true;TxPhyLoan::gate(true);started=lastOn=cyc();armNext(onCycles,started);
 }
 const uint32_t expectedTone=TxPhyLoan::rd(TxPhyLoan::Tone1)&~TxPhyLoan::Gate;
 out.prepared=ok;
 out.maxIrqUs=(cyc()-entry)/160u;
 __asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
 if(ok){
  uint32_t checked=started,fed=started;
  // No cooperative SDK scheduling here. system_soft_wdt_feed is the audited
  // alias pp_soft_wdt_feed: one RAM flag and hardware WDT-feed register only.
  while(!done){
   const uint32_t now=cyc();
   if(uint32_t(now-started)>=durationCycles+320000u){
    __asm__ volatile("rsil %0,15\n\trsync":"=a"(ps)::"memory");abortCode=3;endGate(now);__asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");break;
   }
   if(uint32_t(now-checked)>=160000u){
    checked=now;uint32_t violation=0;
    if(TxPhyLoan::rd(IntEna)!=0)violation=4;
    if(WebSdrCapture::rd(WebSdrCapture::MacRxControl)&WebSdrCapture::MacRxEnable)violation=5;
    if(!(WebSdrCapture::rd(WebSdrCapture::RxCtrl)&WebSdrCapture::RxStop))violation=6;
    for(uint8_t q=0;q<8;++q)if(TxPhyLoan::rd(0x3FF20DC4u-24u*q)&0xC0000000u)violation=7;
    if((TxPhyLoan::rd(TxPhyLoan::Tone1)&~TxPhyLoan::Gate)!=expectedTone)violation=8;
    if(!(TxPhyLoan::rd(TxPhyLoan::PbusCmd)&1u))violation=9;
    if((TxPhyLoan::rd(TxPhyLoan::Tone2)|TxPhyLoan::rd(TxPhyLoan::Tone3))&TxPhyLoan::Gate)violation=10;
    if(violation){__asm__ volatile("rsil %0,15\n\trsync":"=a"(ps)::"memory");abortCode=violation;endGate(cyc());__asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");break;}
   }
   if(uint32_t(now-fed)>=8000000u){ESP.wdtFeed();fed=now;}
   __asm__ volatile("nop");
  }
 }
 __asm__ volatile("rsil %0,15\n\trsync":"=a"(ps)::"memory");
 const uint32_t cleanup=cyc();timer1_disable();timer1_detachInterrupt();TxPhyLoan::gate(false);
 if(ok){out.elapsedUs=uint32_t(finished-started)/160u;out.onUs=totalOn/160u;out.edges=edges;out.abortCode=abortCode;if(out.elapsedUs>durationUs)out.deadlineLateUs=out.elapsedUs-durationUs;}
 out.restored=TxPhyLoan::restore(saved);
 WebSdrCapture::wr(WebSdrCapture::RxCtrl,(WebSdrCapture::rd(WebSdrCapture::RxCtrl)&~WebSdrCapture::RxStop)|oldStop);
 out.restored=out.restored&&((WebSdrCapture::rd(WebSdrCapture::RxCtrl)&WebSdrCapture::RxStop)==oldStop);
 const uint32_t cleanupUs=(cyc()-cleanup)/160u;if(cleanupUs>out.maxIrqUs)out.maxIrqUs=cleanupUs;
 __asm__ volatile("wsr.ps %0\n\trsync"::"a"(ps):"memory");
 // Caller MUST endSession() while WDEV events remain masked, then invoke
 // restoreInterrupts() before yielding/PM0. Never clear WDEV status/ACK C24.
 return ok&&out.restored&&!out.abortCode;
}
}

// ===== END integrated long_tx.h =====
static ESP8266WebServer http(80);
namespace BoomTx {
static TxConfig::Value config,applied;
static Heartbeat::Lease lease;
static LongTx::Stats last;
static ControlMessages::Request deferredRpc[4];
static uint8_t deferredCount=0;
static uint32_t deferredEpoch=0,challengeWireEnd=0;
static bool initialized=false,faulted=false,recovering=false,quiet=false,needChallenge=false;
static const char *fault="",*lastEvent="boot";
static char peerId[33]={};
static uint32_t peerEpoch=0,ownerEpoch=0,revision=1,appliedRevision=0,cycleNumber=0;
static uint32_t quietUntil=0,retryAt=0,grantAtMs=0;
static uint32_t blocks=0,busySkips=0,restoreFailures=0,pmFailures=0,confirmations=0,rejectedConfirmations=0,recoveryAttempts=0;
static uint64_t txUs=0,observedUs=0,sessionOnUs=0,sessionElapsedUs=0;
static uint32_t observedAt=0;
static constexpr uint32_t ConfirmationMs=3000,GrantFreshMs=500,WifiServiceUs=3000;
static void account(){uint32_t now=micros();uint32_t delta=now-observedAt;observedUs+=delta;if(lease.enabled())sessionElapsedUs+=delta;observedAt=now;}
static bool enabled(){return lease.enabled();}
static void stop(const char *reason){account();lease.stop();needChallenge=false;lastEvent=reason;}
static void fail(const char *reason){stop(reason);faulted=true;fault=reason;}
static void quietWindow(){quiet=true;quietUntil=micros()+WifiServiceUs;}
static bool pm(bool value){bool ok=PowerSaveControl::send(value,DirectSession::bssid);if(!ok)++pmFailures;return ok;}
static void appendConfig(String &s,const TxConfig::Value &v){s+="{\"frequencyMHz\":";s+=v.frequencyMHz;s+=",\"ask\":";s+=v.ask;s+=",\"apwr\":";s+=v.apwr;s+=",\"dutyPercent\":";s+=v.dutyPercent;s+=",\"periodMs\":";s+=v.periodUs/1000u;s+=",\"networkIntervalMs\":";s+=v.networkIntervalMs;s+='}';}
static void appendStatus(String &s){
 account();const uint64_t elapsed=sessionElapsedUs;
 s+="{\"firmware\":\"ESPBoOm8266TX 0.2.0\",\"boot\":";s+=DirectSession::boot;
 s+=",\"state\":\"";s+=faulted?"fault":(!initialized?"connecting":(recovering?"recovering":((lease.awaiting()||needChallenge)?"awaiting_confirmation":(enabled()?"running":"idle"))));
 s+="\",\"enabled\":";s+=enabled()?"true":"false";s+=",\"running\":";s+=enabled()?"true":"false";
 s+=",\"fault\":\"";s+=fault;s+="\",\"lastEvent\":\"";s+=lastEvent;s+="\",\"sessionId\":";s+=lease.sessionId();s+=",\"cycle\":";s+=cycleNumber;
 s+=",\"revision\":";s+=revision;s+=",\"appliedRevision\":";s+=appliedRevision;
 s+=",\"wifiRssiDbm\":";s+=WiFi.RSSI();
 s+=",\"wifiIP\":\"";s+=WiFi.localIP().toString();s+="\",\"mac\":\"";s+=WiFi.macAddress();s+="\",\"config\":";appendConfig(s,config);
 s+=",\"applied\":";if(appliedRevision)appendConfig(s,applied);else s+="{}";
 s+=",\"control\":{\"webSocketUrl\":\"";
 s+="ws://";
 s+=WiFi.localIP().toString();s+=":81/ws\",\"confirmationTimeoutMs\":3000},\"limits\":{\"frequencyMinMHz\":2412,\"frequencyMaxMHz\":2462,\"frequencyStepMHz\":1,\"askMin\":0,\"askMax\":63,\"apwrMin\":0,\"apwrMax\":127,\"dutyMinPercent\":0,\"dutyMaxPercent\":90,\"periodMinMs\":2,\"periodMaxMs\":100},\"metrics\":{\"completedBlocks\":";s+=blocks;
 s+=",\"phaseDutyPercent\":";s+=String(last.elapsedUs?100.0*last.onUs/last.elapsedUs:0,3);
 s+=",\"globalDutyPercent\":";s+=String(elapsed?100.0*double(sessionOnUs)/elapsed:0,3);
 s+=",\"txUs\":";s+=String(double(txUs),0);s+=",\"nonTxUs\":";s+=String(double(observedUs-txUs),0);
 s+=",\"uptimeMs\":";s+=millis();s+=",\"restoreFailures\":";s+=restoreFailures;s+=",\"busySkips\":";s+=busySkips;s+=",\"pmFailures\":";s+=pmFailures;
 s+=",\"confirmations\":";s+=confirmations;s+=",\"rejectedConfirmations\":";s+=rejectedConfirmations;s+=",\"recoveryAttempts\":";s+=recoveryAttempts;
 s+=",\"lastBlockUs\":";s+=last.elapsedUs;s+=",\"lastOnUs\":";s+=last.onUs;s+=",\"timerEdges\":";s+=last.edges;
 s+=",\"maxEntryCleanupIrqUs\":";s+=last.maxIrqUs;s+=",\"deadlineLateUs\":";s+=last.deadlineLateUs;s+=",\"radioAbortCode\":";s+=last.abortCode;
 s+=",\"associationCount\":";s+=DirectSession::associations;s+=",\"disconnectCount\":";s+=DirectSession::disconnects;s+=",\"freeHeap\":";s+=ESP.getFreeHeap();s+="}}";
}
static String statusBody(){String s;s.reserve(2100);appendStatus(s);return s;}
static void status(){http.sendHeader("Cache-Control","no-store");http.send(200,"application/json",statusBody());}
static void error(int code,const char *reason){http.send(code,"application/json",String("{\"error\":\"")+reason+"\"}");}
static void wsStatus(){if(!IQSocket.connected())return;String s;s.reserve(2150);s="{\"type\":\"status\",\"status\":";appendStatus(s);s+='}';IQSocket.sendText(s.c_str(),s.length(),1000);}
static int dispatch(const char *path,const char *method,const char *body,const char *&reason);
static void replyRpc(const ControlMessages::Request &rpc){
  const char *reason="";int code=dispatch(rpc.path,rpc.method,rpc.body,reason);
  String out;out.reserve(2300);out="{\"type\":\"response\",\"requestId\":";out+=rpc.requestId;out+=",\"httpStatus\":";out+=code;out+=",\"data\":";
  if(code==200)appendStatus(out);else{out+="{\"error\":\"";out+=reason;out+="\"}";}out+='}';
  IQSocket.sendText(out.c_str(),out.length(),1000);
}
static void serveDeferred(){
 if(!deferredCount)return;
 if(deferredEpoch!=IQSocket.epoch()||!IQSocket.connected()){deferredCount=0;return;}
 const uint8_t count=deferredCount;deferredCount=0;
 for(uint8_t i=0;i<count&&deferredEpoch==IQSocket.epoch()&&IQSocket.connected();++i)replyRpc(deferredRpc[i]);
}
static void challenge(){
 serveDeferred();
 if(!lease.active())return;
 if(!IQSocket.controlEstablished()||IQSocket.epoch()!=ownerEpoch||strcmp(peerId,lease.clientId())){stop("control_disconnected");return;}
 ++cycleNumber;needChallenge=true;wsStatus();
 const uint32_t nonce=os_random();
 char s[192];snprintf(s,sizeof(s),"{\"type\":\"challenge\",\"sessionId\":%lu,\"cycle\":%lu,\"nonce\":%lu}",lease.sessionId(),cycleNumber,nonce);
 if(!IQSocket.sendText(s,strlen(s),1000)){stop("challenge_send_failed");return;}
 // A matching page reply proves receipt of this nonce and all preceding
 // server data; do not block application input waiting for a TCP ACK.
 needChallenge=false;
 if(!lease.issue(cycleNumber,nonce,millis(),ConfirmationMs)){fail("challenge_state");return;}
 challengeWireEnd=IQSocket.stats().wireTxBytes;
}
static void message(const char *data,size_t length){
 account();
 if(length>1024||memchr(data,0,length)){++rejectedConfirmations;return;}
 ControlMessages::Request rpc;
 if(ControlMessages::parseRequest(data,rpc)){
  if(enabled()&&strcmp(rpc.path,"/api/stop")&&strcmp(rpc.path,"/api/start")){
   if(deferredCount==4){stop("control_queue_overflow");serveDeferred();replyRpc(rpc);return;}
   if(!deferredCount)deferredEpoch=IQSocket.epoch();deferredRpc[deferredCount++]=rpc;return;
  }
  replyRpc(rpc);return;
 }
 char id[33];ControlMessages::Confirm value;
 if(ControlMessages::parseStop(data)){stop("user_stop");wsStatus();return;}
 if(ControlMessages::parseHello(data,id)){
  if(enabled()&&(ownerEpoch!=IQSocket.epoch()||strcmp(id,lease.clientId())))stop("control_changed");
  memcpy(peerId,id,sizeof(peerId));peerEpoch=IQSocket.epoch();if(!enabled())wsStatus();return;
 }
 if(ControlMessages::parseConfirm(data,value)){
  if(IQSocket.epoch()!=ownerEpoch||peerEpoch!=ownerEpoch||!lease.confirm(value.clientId,value.sessionId,value.cycle,value.nonce,value.continueTx,millis())){
   ++rejectedConfirmations;if(!lease.enabled())lastEvent=value.continueTx?"confirmation_expired":"page_stop";
  }else{++confirmations;grantAtMs=millis();lastEvent="page_confirmed";IQSocket.pauseInput();}
  return;
 }
 ++rejectedConfirmations;
}
static void recover(){
 if(!recovering||int32_t(micros()-retryAt)<0)return;
 ++recoveryAttempts;
 if(pm(false)){recovering=false;quietWindow();if(enabled())lastEvent="wifi_recovered";}
 else retryAt=micros()+500000u;
}
static void needsRecovery(){recovering=true;retryAt=micros()+500000u;lastEvent="wifi_recovery";}
static void block(){
 if(!lease.active()||quiet||recovering||faulted)return;
 if(!IQSocket.connected()||IQSocket.epoch()!=ownerEpoch){stop("control_disconnected");return;}
 if(uint32_t(millis()-grantAtMs)>=GrantFreshMs){challenge();return;}
 if(IQSocket.stats().wireTxBytes!=challengeWireEnd){challenge();return;}
 delay(3); // Finish ACK/MAC service at HOME before PM1 and the RF loan.
 if(!lease.active()||!IQSocket.controlEstablished()||WiFi.status()!=WL_CONNECTED||IQSocket.epoch()!=ownerEpoch){stop("control_disconnected");return;}
 if(uint32_t(millis()-grantAtMs)>=GrantFreshMs){challenge();return;}
 const auto before=WifiContextSnapshot::read(DirectSession::bssid,DirectSession::boot,DirectSession::associations,DirectSession::disconnects,DirectSession::gotIp);
 DirectSession::inTransaction=true;
 if(!pm(true)){
  bool awake=pm(false);DirectSession::inTransaction=false;++busySkips;lastEvent="pm_entry_busy";if(awake){quietWindow();challenge();}else needsRecovery();return;
 }
 const bool opened=WebSdrCapture::beginSession();
 const bool prepared=opened&&WebSdrCapture::prepareWindow(config.frequencyMHz,2);
 const bool fresh=uint32_t(millis()-grantAtMs)<GrantFreshMs;
 last={};const bool emitted=prepared&&fresh&&LongTx::run(uint32_t(config.networkIntervalMs)*1000u,config.periodUs,config.dutyPercent,config.ask,config.apwr,last);
 txUs+=last.onUs;sessionOnUs+=last.onUs;
 const bool home=opened?WebSdrCapture::endSession():!WebSdrCapture::status().restoreFailures;
 if(!home){TxPhyLoan::gate(false);ESP.reset();return;}
 last.interruptRestored=LongTx::restoreInterrupts();
 if(!last.interruptRestored){TxPhyLoan::gate(false);ESP.reset();return;}
 const bool awake=pm(false);if(awake)quietWindow();
 const auto after=WifiContextSnapshot::read(DirectSession::bssid,DirectSession::boot,DirectSession::associations,DirectSession::disconnects,DirectSession::gotIp);
 DirectSession::inTransaction=false;account();
 if(!last.restored||!WifiContextSnapshot::sameConnection(before,after)){++restoreFailures;fail("radio_restore_failed");return;}
 if(!emitted){if(last.abortCode>=3){fail("radio_guard_aborted");return;}++busySkips;lastEvent="radio_busy";}
 else{++blocks;applied=config;appliedRevision=revision;lastEvent="block_completed";}
 if(!awake){needsRecovery();return;}
 needChallenge=true; // Service queued commands at HOME before the next challenge.
}
static int dispatch(const char *path,const char *method,const char *body,const char *&reason){
 if(!strcmp(path,"/api/status")&&!strcmp(method,"GET"))return 200;
 if(strcmp(method,"POST")){reason="Method not allowed";return 405;}
 if(!strcmp(path,"/api/stop")){stop("user_stop");return 200;}
 if(!strcmp(path,"/api/config")){
  TxConfig::Value next;if(strlen(body)>256||!TxConfig::parse(body,next)){reason="Invalid configuration";return 400;}
  config=next;++revision;if(!config.dutyPercent)stop("zero_duty");return 200;
 }
 if(!strcmp(path,"/api/start")){
  char id[33];if(!ControlMessages::parseStart(body,id)){reason="Invalid client identity";return 400;}
  if(faulted||recovering||!initialized||!config.dutyPercent||!IQSocket.connected()||peerEpoch!=IQSocket.epoch()||strcmp(peerId,id)){reason="Control socket and radio must be ready";return 409;}
  if(enabled()){reason="Transmission is already enabled";return 409;}
  ownerEpoch=IQSocket.epoch();cycleNumber=0;account();sessionOnUs=0;sessionElapsedUs=0;
  if(!lease.start(id,os_random()|1u)){reason="Invalid session";return 400;}
  lastEvent="user_start";needChallenge=true;return 200;
 }
 reason="Not found";return 404;
}
static void api(const char *path){const String payload=http.arg("plain");const char *reason="";int code=dispatch(path,"POST",payload.c_str(),reason);if(code==200)status();else error(code,reason);}
static void begin(){
 observedAt=micros();IQSocket.onMessage(message);
 http.on("/",HTTP_GET,[]{http.sendHeader("Content-Encoding","gzip");http.sendHeader("Cache-Control","no-store");http.send_P(200,"text/html; charset=utf-8",reinterpret_cast<const char*>(sdrPageGzip),sizeof(sdrPageGzip));});
 http.on("/api/status",HTTP_GET,status);http.on("/health",HTTP_GET,status);
 http.on("/api/stop",HTTP_POST,[]{api("/api/stop");});
 http.on("/api/config",HTTP_POST,[]{api("/api/config");});
 http.on("/api/start",HTTP_POST,[]{api("/api/start");});
 http.onNotFound([]{error(404,"Not found");});http.begin();
}
static void poll(){
 account();
 if(WiFi.status()==WL_CONNECTED&&!DirectSession::configured){initialized=iqTuneFrequency(DirectSession::centerMHz());DirectSession::configured=initialized;if(!initialized)fail("radio_initialization_failed");}
 if(peerEpoch!=IQSocket.epoch()){peerEpoch=IQSocket.epoch();peerId[0]=0;deferredCount=0;if(enabled())stop("control_disconnected");}
 if(enabled()&&!IQSocket.connected())stop("control_disconnected");
 if(lease.expire(millis())){lastEvent="confirmation_timeout";wsStatus();}
 if(quiet&&int32_t(micros()-quietUntil)>=0)quiet=false;
 http.handleClient();recover();
 if(!enabled())serveDeferred();
 if(needChallenge&&lease.active())challenge();
 // Recovery cannot itself renew page authorization. Return to the page before RF.
 if(!recovering&&lease.active()&&!strcmp(lastEvent,"wifi_recovered"))challenge();
 block();
}
}
void setup(){serialBaud=0;configuredPaceUs=0;manualGain=0;DirectSession::begin();BoomTx::begin();}
void loop(){DirectSession::poll();BoomTx::poll();yield();}
